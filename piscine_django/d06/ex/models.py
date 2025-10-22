from django.db import models
from django.forms import ModelForm
from django.contrib.auth.models import AbstractUser
from django.conf import settings

class CustomUser(AbstractUser):
	reputation = models.IntegerField(default=0)
	def __str__(self):
		return self.username

	def has_perm(self, perm, obj = ...):
		if self.is_superuser:
			return True
		if perm == "ex.can_downvote_tip":
			return self.reputation >= 15
		if perm == "ex.can_delete_tip":
			return self.reputation >= 30
		return super().has_perm(perm, obj)


# Create your models here.
class Tip(models.Model):
	content = models.CharField(max_length=255, unique=True, null=False)
	author = models.ForeignKey(settings.AUTH_USER_MODEL, on_delete=models.CASCADE)
	date = models.DateField(auto_now_add=True)
	downvotes = models.ManyToManyField(settings.AUTH_USER_MODEL, related_name='downvoted_tips', blank=True)
	upvotes = models.ManyToManyField(settings.AUTH_USER_MODEL, related_name='upvoted_tips', blank=True)
	def __str__(self):
		return self.content

	class Meta:
		permissions = [
			("can_downvote_tip", "Can upvote or downvote tips"),
		]
  
class TipForm(ModelForm):
	class Meta:
		model = Tip
		fields = ['content']
