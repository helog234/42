from django.db import models
from utils import BaseMovie
from django.db.models.signals import pre_save
from django.dispatch import receiver
from django.utils import timezone

# Create your models here.

class Planets(models.Model):
	name = models.CharField(max_length=64, unique=True, null=False)
	climate = models.CharField(max_length=64, null=True)
	diameter = models.IntegerField(null=True)
	orbital_period = models.IntegerField(null=True)
	population = models.BigIntegerField(null=True)
	rotation_period = models.IntegerField(null=True)
	surface_water = models.FloatField(null=True)
	terrain = models.CharField(max_length=128, null=True)
	created = models.DateTimeField(auto_now_add=True, null=True, blank=True)
	updated = models.DateTimeField(auto_now=True, null=True, blank=True)

	def __str__(self):
		return self.name

class People(models.Model):
	name = models.CharField(max_length=64, unique=True, null=False)
	birth_year = models.CharField(max_length=32, null=True)
	gender = models.CharField(max_length=32, null=True)
	eye_color = models.CharField(max_length=32, null=True)
	hair_color = models.CharField(max_length=32, null=True)
	height = models.IntegerField(null=True)
	mass = models.FloatField(null=True)
	homeworld = models.ForeignKey(Planets, on_delete=models.CASCADE, null=True, blank=True)
	created = models.DateTimeField(auto_now_add=True, null=True, blank=True)
	updated = models.DateTimeField(auto_now=True, null=True, blank=True)
 
	def __str__(self):
		return self.name

# Signal handlers to set created and updated fields 
# when loading from fixtures if no created/updated value is provided
@receiver(pre_save, sender=Planets)
def planets_pre_save(sender, instance, **kwargs):
    if kwargs.get('raw'):
        now = timezone.now()
        if not instance.pk:
            instance.created = now
        instance.updated = now

@receiver(pre_save, sender=People)
def people_pre_save(sender, instance, **kwargs):
    if kwargs.get('raw'):
        now = timezone.now()
        if not instance.pk:
            instance.created = now
        instance.updated = now

class Movies(BaseMovie):
    characters = models.ManyToManyField(People, related_name='movies')
