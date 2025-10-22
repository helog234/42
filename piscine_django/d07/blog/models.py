from django.db import models
from django.contrib.auth.models import User

# Create your models here.

class Article(models.Model):
	title = models.CharField(max_length=64)
	content = models.TextField()
	author = models.ForeignKey(User, on_delete=models.CASCADE)
	synopsis = models.CharField(max_length=312)
	created = models.DateTimeField(auto_now_add=True)
 
	class Meta:
		ordering = ['-created']

	def __str__(self):
		return self.title

class UserFavouriteArticle(models.Model):
	user = models.ForeignKey(User, on_delete=models.CASCADE)
	article = models.ForeignKey(Article, on_delete=models.CASCADE)

	class Meta:
		unique_together = ('user', 'article')

	def __str__(self):
		return f"{self.article.title}"