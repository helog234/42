from django.urls import path
from . import views
from django.contrib.auth import views as auth_views
from django.shortcuts import redirect

app_name = 'blog'

urlpatterns = [
    path('', lambda request: redirect('articles/'), name='home'),
    path('articles/', views.ArticleListView.as_view(), name='articles-list'),
    path('login/', auth_views.LoginView.as_view(template_name='blog/login.html', next_page='blog:articles-list'), name='login'),
	path('logout/', auth_views.LogoutView.as_view(next_page='blog:articles-list'), name='logout'),
    path('register/', views.RegisterView.as_view(), name='register'),
	path('articles/<int:pk>/', views.ArticleDetailView.as_view(), name='article-detail'),
	path('articles/new/', views.ArticleCreateView.as_view(), name='article-create'),
	path('my-publications/', views.PublicationListView.as_view(), name='publication-list'),
	path('articles/<int:article_pk>/favourite/', views.UserFavouriteArticleCreateView.as_view(), name='favourite-article'),
	path('favourite-articles/', views.UserFavouriteArticleListView.as_view(), name='favourite-article-list'),
]