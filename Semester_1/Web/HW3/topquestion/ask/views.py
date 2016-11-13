from django.shortcuts import render_to_response, render
from helper import pagination

def init():
  questions = []
  for i in xrange(1,30):
    questions.append({
      'head' : 'title' + str(i),
      'text' : 'text' + str(i),
      'tags' : ['1', '2', '3'],
      'answers' : [{'text' : 'answer1'}, {'text' : 'answer2'}],
      'id' : i - 1,
    })
  hot_tags = ['tag1', 'tag2', 'tag3']
  loged = 1
  return { 'questions' : questions, 'hot_tags' : hot_tags, 'loged' : loged }

def index(request):  
  init_list = init()
  tag = init_list['hot_tags'][0]
  return render_to_response('index.html', {'questions_page_title' : 'Questions', 'questions' : pagination(request), 'tags' : init_list['hot_tags'], 'isLogging' : init_list['loged'] })

def questions(request):
  init_list = init()
  return render_to_response('questions.html', {'questions_page_title' : 'Questions', 'questions' : pagination(request), 'tags' : init_list['hot_tags'], 'isLogging' : init_list['loged'] })

def question(request, id):
  init_list = init()
  return render_to_response('question.html', {'questions' : init_list['questions'][int(id)]})

def questions_tag(request, tag):
  init_list = init()
  return render_to_response('questions_tag.html', {'tag' : tag, 'questions_page_title' : 'tag: ' + tag, 'questions' : pagination(request), 'tags' : init_list['hot_tags'], 'isLogging' : init_list['loged']})

def login(request):
  init_list = init()
  tag = init_list['hot_tags'][0]
  return render_to_response('login.html', {'questions_page_title' : 'Questions', 'questions' : init_list['questions'], 'tags' : init_list['hot_tags'], 'isLogging' : init_list['loged'] })

def signup(request):
  init_list = init()
  return render_to_response('signup.html', {'tags' : init_list['hot_tags'], 'isLogging' : init_list['loged']})

def ask_page(request):
  init_list = init()
  return render_to_response('ask.html', {'tags' : init_list['hot_tags'], 'isLogging' : init_list['loged']})

def user(request):
  init_list = init()
  return render_to_response('user_settings.html', {'tags' : init_list['hot_tags'], 'isLogging' : init_list['loged']})
