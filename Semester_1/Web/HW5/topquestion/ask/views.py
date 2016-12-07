from django.shortcuts import render, render_to_response, get_object_or_404
from django.http import HttpResponse, HttpResponseRedirect, Http404
from django.contrib import auth
from django.views.decorators.csrf import csrf_exempt
from django.contrib.auth.decorators import login_required
from django.views.decorators.http import require_POST
from django.core.urlresolvers import reverse
from django.forms.models import model_to_dict
from django.contrib.auth.models import User
import json
from ask.models import *
from ask.forms import *
from ask.helper import pagination, randomTags


def index(request, page='1'):
	questions = pagination(request, Question.objects.newest(), 5, page)
	questions.paginator.baseurl = "/"
	return render_to_response('questions.html',
														{'questions_page_title': 'Questions', 'questions': questions, 'tags': randomTags(Tag)})


def questions(request, page='1'):
	questions = pagination(request, Question.objects.newest(), 5, page)
	questions.paginator.baseurl = "/hot/"
	return render_to_response('questions.html',
														{'questions_page_title': 'Questions', 'questions': questions, 'tags': randomTags(Tag)})


def question(request, id):
	question_ = get_object_or_404(Question, pk=id)
	answers = question_.answer_set.all()
	return render_to_response('question.html',
														{'question': question_, 'answers': answers, 'tags': randomTags(Tag)})


def questions_tag(request, tag, page='1'):
	tag_questions = Question.objects.tag_search(tag)
	questions = pagination(request, tag_questions, 5, page)
	questions.paginator.baseurl = "/tag/" + tag + "/"
	return render('questions_tag.html', {'tag': tag, 'questions': questions, 'tags': randomTags(Tag),
																									 'questions_page_title': 'Tag: ' + tag})


def login(request):
	redirect = request.GET.get('continue', '/')
	if request.user.is_authenticated():
		return HttpResponseRedirect(redirect)
	if request.method == "POST":
		form = LoginForm(request.POST)

		if form.is_valid():
			auth.login(request, form.cleaned_data['user'])
			return HttpResponseRedirect(redirect)
	else:
		form = LoginForm()
	return render(request, 'login.html', {'tags': randomTags(Tag), 'form': form})


def signup(request):
	if request.user.is_authenticated():
		return HttpResponseRedirect('/')
	if request.method == "POST":
		form = SignupForm(request.POST, request.FILES)
		if form.is_valid():
			user = form.save()
			auth.login(request, user)
			return HttpResponseRedirect('/')
	else:
		form = SignupForm()
	return render(request, 'signup.html', {'tags': randomTags(Tag), 'form': form})

@login_required
def logout(request):
	redirect = request.GET.get('continue', '/')
	auth.logout(request)
	return HttpResponseRedirect(redirect)


def ask_page(request):
	return render(request, 'ask.html', {'tags': randomTags(Tag)})


def user(request, user_name):
	user = Question.objects.user_questions(user_name)
	profile = Profile.objects.get_by_name(user_name)
	return render(request, 'user_settings.html',
														{'user': user, 'profile': profile[0], 'tags': randomTags(Tag)})
