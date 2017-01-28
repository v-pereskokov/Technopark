from django.shortcuts import render_to_response, get_object_or_404
from django.http import Http404
from django.views.decorators.csrf import csrf_exempt
from django.contrib.auth.models import User
from ask.models import *
from ask.helper import pagination
import numpy as np


def randomTags():
	tags = []
	for i in range(Tag.objects.count()):
		tags.append(str(Tag.objects.get(id=i + 1)))
	np.random.shuffle(tags)
	return tags[:3]


def index(request, page='1'):
	questions = pagination(request, Question.objects.hot(), 5, page)
	questions.paginator.baseurl = "/"
	return render_to_response('questions.html',
	                          {'questions_page_title': 'Questions', 'questions': questions, 'tags': randomTags(),
	                           'isLogging': False})


def questions(request, page='1'):
	questions = pagination(request, Question.objects.newest(), 5, page)
	questions.paginator.baseurl = "/hot/"
	return render_to_response('questions.html',
	                          {'questions_page_title': 'Questions', 'questions': questions, 'tags': randomTags(),
	                           'isLogging': False})


def question(request, id):
	question_ = get_object_or_404(Question, pk=id)
	answers = question_.answer_set.all()
	return render_to_response('question.html',
	                          {'question': question_, 'answers': answers, 'tags': randomTags(), 'isLogging': False})


def questions_tag(request, tag, page='1'):
	tag_questions = Question.objects.tag_search(tag)
	questions = pagination(request, tag_questions, 5, page)
	questions.paginator.baseurl = "/tag/" + tag + "/"
	return render_to_response('questions_tag.html', {'tag': tag, 'questions': questions, 'tags': randomTags(),
	                                                 'questions_page_title': 'Tag: ' + tag, 'isLogging': False})


def login(request):
	return render_to_response('login.html', {'isLogging': False, 'tags': randomTags()})


def signup(request):
	return render_to_response('signup.html', {'isLogging': False, 'tags': randomTags()})


def ask_page(request):
	return render_to_response('ask.html', {'isLogging': False, 'tags': randomTags()})


def user(request, user_name):
	is_logging = {'isLogging': False}
	random_tags = {'tags': randomTags()}
	user = Question.objects.user_questions(user_name)
	profile = Profile.objects.get(user_name)
	return render_to_response('user_settings.html',
	                          {'user': user, 'profile': profile[0], 'isLogging': False, 'tags': randomTags()})
