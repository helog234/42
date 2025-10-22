# forms.py signin form and login form

from django import forms
from django.contrib.auth import get_user_model
from django.contrib.auth import authenticate

User = get_user_model()

class SignInForm(forms.Form):
    username = forms.CharField(max_length=100, required=True, min_length=3)
    password = forms.CharField(widget=forms.PasswordInput(), required=True, min_length=6)
    repeat_password = forms.CharField(widget=forms.PasswordInput(), required=True, min_length=6)
    
    def clean_username(self):
        username = self.cleaned_data.get('username')
        if User.objects.filter(username=username).exists():
            raise forms.ValidationError("Username already exists! Please choose another one.")
        return username
    
    def clean(self):
        cleaned_data = super().clean()
        password = cleaned_data.get("password")
        repeat_password = cleaned_data.get("repeat_password")

        if password != repeat_password:
            raise forms.ValidationError(
                "Passwords do not match!"
            )
        return cleaned_data

class LoginForm(forms.Form):
    username = forms.CharField(max_length=150)
    password = forms.CharField(widget=forms.PasswordInput)
    
    def __init__(self, *args, **kwargs):
        self.request = kwargs.pop('request', None)
        super().__init__(*args, **kwargs)
    
    def clean(self):
        cleaned_data = super().clean()
        username = cleaned_data.get('username')
        password = cleaned_data.get('password')
        
        if username and password:
            self.user_cache = authenticate(username=username, password=password)
            if self.user_cache is None:
                raise forms.ValidationError("Invalid username or password.")
            if not self.user_cache.is_active:
                raise forms.ValidationError("This account is inactive.")
        
        return cleaned_data
    
    def get_user(self):
        return self.user_cache