from django.contrib.auth.forms import UserCreationForm
from django import forms

class CustomUserCreationForm(UserCreationForm):
    
    username = forms.CharField(
        max_length=100, 
        required=True, 
        min_length=3,
        help_text="Required. 3-100 characters."
    )
    
    password1 = forms.CharField(
        label="Password",
        widget=forms.PasswordInput,
        required=True, 
        min_length=6
    )

    password2 = forms.CharField(
        label="Confirm password",
        widget=forms.PasswordInput, 
        required=True, 
        min_length=6
    )
    class Meta(UserCreationForm.Meta):
        fields = ('username', 'password1', 'password2')