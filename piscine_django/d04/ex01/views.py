from django.shortcuts import render

# Create your views here.
def base(request):
    return render(request, 'base.html')

def nav(request):
    return render(request, 'nav.html')

def django(request):
    return render(request, 'ex01/django.html')

def affichage(request):
    return render(request, 'ex01/affichage.html')

def templates(request):
    return render(request, 'ex01/templates.html')