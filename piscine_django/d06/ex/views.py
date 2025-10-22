from django.views import View
from django.views.generic import ListView, CreateView
from django.http import HttpResponse, HttpRequest
from django.shortcuts import render, redirect
from .forms import SignInForm, LoginForm
from django.contrib.auth import authenticate, login, logout, get_user_model
from django.conf import settings
from .models import Tip, TipForm
import random
from django.contrib.auth.views import LoginView as DjangoLoginView, LogoutView as DjangoLogoutView
from django.urls import reverse_lazy

User = get_user_model()

class IndexView(View):
	def get(self, request):
		random_name = None
		if not request.user.is_authenticated:
			if 'name' not in request.session:
				request.session['name'] = random.choice(settings.RANDOM_NAMES)
				request.session.set_expiry(42)
			random_name = request.session.get('name')
		tips = Tip.objects.all().order_by('-date')
		form = TipForm()
		return render(request, 'index.html', {'tips': tips, 'random_name': random_name, 'form': form})

	def post(self, request):
		if 'add_tip' in request.POST:
			if request.user.is_authenticated:
				form = TipForm(request.POST)
				if form.is_valid():
					new_tip = form.save(commit=False)
					new_tip.author = request.user
					new_tip.save()
					return redirect('ex:index')
				else:
					return HttpResponse(f"Error: {form.errors}", status=400)
			else:
				return HttpResponse("You do not have permission to add a tip.", status=403)
		elif 'delete_tip' in request.POST:
			tip_id = request.POST.get('delete_tip')
			try:
				tip = Tip.objects.get(id=tip_id)
				if request.user.is_authenticated and (request.user == tip.author or request.user.has_perm('ex.can_delete_tip')):
					tip.delete()
					return redirect('ex:index')
				else:
					return HttpResponse("You do not have permission to delete this tip.", status=403)
			except Tip.DoesNotExist:
				return HttpResponse("Tip not found.", status=404)
		else:
			return HttpResponse("Invalid request.", status=400)

class SignupView(View):
	def get(self, request):
		form = SignInForm()
		return render(request, 'signup.html', {'form': form})

	def post(self, request):
		form = SignInForm(request.POST)
		if form.is_valid():
			username = form.cleaned_data['username']
			password = form.cleaned_data['password']
			user = User.objects.create_user(username=username, password=password)
			login(request, user)
			return redirect('ex:index')
		else:
			return render(request, 'signup.html', {'form': form})

class LoginView(DjangoLoginView):
	form_class = LoginForm
	template_name = 'login.html'
	success_url = reverse_lazy('ex:index')
	
	def get_success_url(self):
		return reverse_lazy('ex:index')

class LogoutView(DjangoLogoutView):
	next_page = reverse_lazy('ex:index')

class TipVoteView(View):
	def post(self, request, tip_id):
		if 'upvote' in request.POST:
			return self.upvote_tip(request, tip_id)
		elif 'downvote' in request.POST:
			return self.downvote_tip(request, tip_id)
		else:
			return HttpResponse("Invalid action.", status=400)

	def upvote_tip(self, request, tip_id):
		tip = Tip.objects.get(id=tip_id)
		author = tip.author
		if request.user.is_authenticated and request.user != author:
			try:
				if (request.user in tip.upvotes.all()):
					tip.upvotes.remove(request.user)
					author.reputation -= 5
				else:
					if (request.user in tip.downvotes.all()):
						tip.downvotes.remove(request.user)
					tip.upvotes.add(request.user)
					author.reputation += 5
				tip.save()
			except Tip.DoesNotExist:
				return HttpResponse("Tip not found.", status=404)
		return redirect('ex:index')

	def downvote_tip(self, request, tip_id):
		tip = Tip.objects.get(id=tip_id)
		author = tip.author
		if request.user.is_authenticated and (request.user == author or request.user.has_perm('ex.can_downvote_tip')):
			try:
				if (request.user in tip.downvotes.all()):
					tip.downvotes.remove(request.user)
					author.reputation += 2
				else:
					if (request.user in tip.upvotes.all()):
						tip.upvotes.remove(request.user)
					tip.downvotes.add(request.user)
					author.reputation -= 2
				tip.save()
			except Tip.DoesNotExist:
				return HttpResponse("Tip not found.", status=404)
		return redirect('ex:index')

def ex00(request: HttpRequest) -> HttpResponse:
	if 'name' not in request.session:
		request.session['name'] = random.choice(settings.RANDOM_NAMES)
		request.session.set_expiry(42)
	name = request.session['name']
	return HttpResponse(f"Hello {name}!")