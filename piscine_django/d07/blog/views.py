from django.shortcuts import render
from .models import Article, UserFavouriteArticle
from django.views.generic import ListView, DetailView, CreateView
from django.urls import reverse_lazy
from django.forms import ModelForm, HiddenInput
from django.contrib.auth.forms import UserCreationForm
from django.contrib import messages
from django.contrib.auth.mixins import LoginRequiredMixin
from django.shortcuts import redirect
from django.utils.translation import gettext as _

# Article Views

class ArticleListView(ListView):
	model = Article
	template_name = 'blog/article_list.html'
	context_object_name = 'articles'

class ArticleDetailView(DetailView):
	model = Article
	template_name = 'blog/article_detail.html'
	context_object_name = 'article'
 
	def get_context_data(self, **kwargs):
		context = super().get_context_data(**kwargs)
		if self.request.user.is_authenticated:
			is_favourite = UserFavouriteArticle.objects.filter(user=self.request.user, article=self.object).exists()
			context['is_favourite'] = is_favourite
		return context

class ArticleCreateView(LoginRequiredMixin, CreateView):
	model = Article
	template_name = 'blog/article_form.html'
	fields = ['title', 'content', 'synopsis']

	def form_valid(self, form):
		form.instance.author = self.request.user
		return super().form_valid(form)

	def get_success_url(self):
		return reverse_lazy('blog:publication-list')

# User Favourite Article Views
class UserFavouriteArticleForm(ModelForm):
    class Meta:
        model = UserFavouriteArticle
        fields = ['article']
        widgets = {
            'article': HiddenInput(),
        }

class UserFavouriteArticleListView(LoginRequiredMixin, ListView):
	model = UserFavouriteArticle
	template_name = 'blog/user_favourite_article_list.html'
	context_object_name = 'favourite_articles'

	def get_queryset(self):
		return UserFavouriteArticle.objects.filter(user=self.request.user)

class UserFavouriteArticleCreateView(LoginRequiredMixin, CreateView):
    model = UserFavouriteArticle
    fields = []
    
    def post(self, request, *args, **kwargs):
        user = self.request.user
        article_id = self.kwargs.get('article_pk')
        
        try:
            article = Article.objects.get(pk=article_id)
        except Article.DoesNotExist:
            messages.error(self.request, _("Article not found."))
            return redirect(reverse_lazy('blog:articles-list'))
        
        already_favourite = UserFavouriteArticle.objects.filter(user=user, article=article).exists()
        
        if not already_favourite:
            UserFavouriteArticle.objects.create(user=user, article=article)
            messages.success(self.request, _("Article added to your favourites."))
        else:
            messages.info(self.request, _("Article is already in your favourites."))

        return redirect(reverse_lazy('blog:article-detail', kwargs={'pk': article_id}))

# Publication List View
class PublicationListView(LoginRequiredMixin, ListView):
	model = Article
	template_name = 'blog/publication_list.html'
	context_object_name = 'articles'

	def get_queryset(self):
		return Article.objects.filter(author=self.request.user)

# User Registration View
class RegisterView(CreateView):
	form_class = UserCreationForm
	template_name = 'blog/register.html'
	success_url = reverse_lazy('blog:login')
 
	def dispatch(self, request, *args, **kwargs):
		if request.user.is_authenticated:
			return redirect('blog:articles-list')
		return super().dispatch(request, *args, **kwargs)


