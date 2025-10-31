from django.shortcuts import render, redirect
from django.contrib.auth.forms import AuthenticationForm
from django.contrib.auth import login, logout
from django.http import HttpResponseBadRequest, JsonResponse
from django.views import View
from .forms import CustomUserCreationForm

def account_view(request):
	if request.user.is_authenticated:
		return redirect('chat_lobby')
	else:
		form = AuthenticationForm()
		context = {'form': form}
	return render(request, 'account/account.html', context)

class LoginView(View):
	def get(self, request, *args, **kwargs):
		form = AuthenticationForm()
		context = {'form': form}
		return render(request, 'account/fragments/login_frag.html', context)

class RegisterView(View):
	def get(self, request, *args, **kwargs):
		form = CustomUserCreationForm()
		context = {'form': form}
		return render(request, 'account/fragments/register_frag.html', context)

def ajax_login_view(request):
    """
    Only manages POST in AJAX.
    """
    if request.method != 'POST':
        return HttpResponseBadRequest("Unauthorized method")

    form = AuthenticationForm(request, data=request.POST)
    if form.is_valid():
        user = form.get_user()
        login(request, user)
        return JsonResponse({'success': True})
    else:
        return render(request, 'account/fragments/login_frag.html', {'form': form}, status=400)

	
def ajax_navbar_view(request):
	"""
	Returns the navbar fragment with current user state
	"""
	return render(request, 'account/fragments/navbar_frag.html', {'user': request.user})


def ajax_logout_view(request):
	"""
	Only managest POST in AJAX.
	"""
	if request.method != 'POST':
		return HttpResponseBadRequest("Méthode non autorisée")

	logout(request)
	form = AuthenticationForm()
	return render(request, 'account/fragments/login_frag.html', {'form': form})

def ajax_register_view(request):
    """
    Only manages POST in AJAX.
    """
    if request.method != 'POST':
        return HttpResponseBadRequest("Unauthorized method")

    form = CustomUserCreationForm(request.POST)
    if form.is_valid():
        user = form.save()
        login(request, user)
        return JsonResponse({'success': True})
    else:
        return render(request, 'account/fragments/register_frag.html', {'form': form}, status=400)