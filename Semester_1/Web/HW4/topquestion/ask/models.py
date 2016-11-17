# -*- coding: utf-8 -*-
from django.db import models
from django.contrib.auth.models import User, UserManager
import datetime

class QuestionManager(models.Manager):
  def newest(self):
    return self.order_by('-created')

  def hot(self):
    return self.order_by('-rating')

  def tag_search(self, input_tag):
    return self.filter(tag__text = input_tag)

  def published(self):
    return self.filter(is_published=True)
  def user_questions(self, user_name):
    return self.filter(user__username = user_name)

class ProfileManager(models.Manager):
  def get(self, user_name):
    return self.filter(user__username = user_name)

class Tag(models.Model):
  text = models.CharField(max_length=50, verbose_name='Tag')

  def __unicode__(self):
    return self.text


class Like(models.Model):
  rating = models.IntegerField(default = 0, db_index=True)

  def __unicode__(self):
    return str(self.rating)


class Question(models.Model):
  user = models.ForeignKey(User)
  title = models.CharField(max_length = 255, verbose_name=u'Title')
  text = models.TextField(verbose_name=u'Text')
  rating = models.IntegerField(verbose_name=u'Rating')
  is_published = models.BooleanField(default=False, verbose_name=u'Published')
  created = models.DateTimeField(default = datetime.datetime.now)
  tag = models.ManyToManyField(Tag)
  id = models.IntegerField(unique=True, primary_key=True)

  objects = QuestionManager()

  def __unicode__(self):
    return self.title

  def __unicode__(self):
    return self.text

class Profile(models.Model):
  user = models.OneToOneField(User)
  avatar = models.ImageField(upload_to='uploads')
  information = models.TextField()
  rating = models.IntegerField()

  objects = ProfileManager()

  def __unicode__(self):
    return unicode(self.user)

class Answer(models.Model):
  user = models.ForeignKey(User)
  question = models.ForeignKey(Question)
  text = models.TextField()
  rating = models.IntegerField(default = 0) 
  data = models.DateTimeField(default = datetime.datetime.now)
  is_correct = models.BooleanField(default = False)
  id = models.IntegerField(primary_key=True)


