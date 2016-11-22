# -*- coding: utf-8 -*-
from django.db import models
from django.contrib.auth.models import User, UserManager
import datetime
from django.utils import timezone

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
  def getName(self, user_name):
    return self.filter(user__username = user_name)

class Tag(models.Model):
  class Meta:
    verbose_name = u'Тэг'
    verbose_name_plural = u'Тэги'

  text = models.CharField(max_length=50, verbose_name='Tag')

  def __unicode__(self):
    return self.text

class Question(models.Model):
  class Meta:
    verbose_name = u'Вопрос'
    verbose_name_plural = u'Вопросы'

  user = models.ForeignKey(User, verbose_name=u'Пользователь')
  title = models.CharField(max_length = 255, verbose_name=u'Заголовок')
  text = models.TextField(verbose_name=u'Текст')
  rating = models.IntegerField(verbose_name=u'Рейтинг')
  is_published = models.BooleanField(default=False, verbose_name=u'Публикация')
  data = models.DateTimeField(default = timezone.now, verbose_name=u'Дата создания')
  tag = models.ManyToManyField(Tag, verbose_name=u'Тэг')
  id = models.IntegerField(unique=True, primary_key=True, verbose_name=u'id')

  objects = QuestionManager()

  def __unicode__(self):
    return self.text

class Profile(models.Model):
  class Meta:
    verbose_name = u'Профиль'
    verbose_name_plural = u'Профили'

  user = models.OneToOneField(User, verbose_name=u'Пользователь')
  avatar = models.ImageField(upload_to='uploads')
  information = models.TextField(verbose_name=u'Информация')
  rating = models.IntegerField(verbose_name=u'Рейтинг')

  objects = ProfileManager()

  def __unicode__(self):
    return unicode(self.user)

class Answer(models.Model):
  class Meta:
    verbose_name = u'Ответ'
    verbose_name_plural = u'Ответы'
  user = models.ForeignKey(User, verbose_name=u'Пользователь')
  question = models.ForeignKey(Question, verbose_name=u'Вопрос')
  text = models.TextField(verbose_name=u'Текст')
  rating = models.IntegerField(default = 0, verbose_name=u'Рейтинг') 
  data = models.DateTimeField(default = timezone.now, verbose_name=u'Дата добавления')
  is_correct = models.BooleanField(default = False, verbose_name=u'Корректность')
  id = models.IntegerField(primary_key=True, verbose_name=u'id')

class QuestionLike(models.Model):
  class Meta:
    verbose_name = u'Рейтинг вопроса'
    verbose_name_plural = u'Рейтинг вопросов'

  rating = models.IntegerField(default = 0, db_index=True, verbose_name=u'Рейтинг')
  question = models.ForeignKey(Question, default = False, verbose_name=u'Вопрос')

  def __unicode__(self):
    return str(self.rating)

class AnswerLike(models.Model):
  class Meta:
    verbose_name = u'Рейтинг ответа'
    verbose_name_plural = u'Рейтинг ответов'

  rating = models.IntegerField(default = 0, db_index=True, verbose_name=u'Рейтинг')
  question = models.ForeignKey(Question, default = False, verbose_name=u'Вопрос')


  def __unicode__(self):
    return str(self.rating)
