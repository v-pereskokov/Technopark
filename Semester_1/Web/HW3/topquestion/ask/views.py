from django.shortcuts import render_to_response

def init():
  questions = []
  for i in xrange(1,30):
    questions.append({
      'head' : 'title' + str(i),
      'text' : 'text' + str(i),
      'tags' : ['tag1', 'tag2', 'tag3'],
    })
  hot_tags = ['tag1', 'tag2', 'tag3']
  loged = None
  return { 'questions' : questions, 'hot_tags' : hot_tags, 'loged' : loged }

def index(request):  
  init_list = init()
  return render_to_response('index.html', {'questions' : init_list['questions'], 'tags' : init_list['hot_tags'], 'isLogging' : init_list['loged'] })

def questions(request):
  init_list = init()
  return render_to_response('questions.html', {'questions' : init_list['questions'], 'tags' : init_list['hot_tags'], 'isLogging' : init_list['loged'], 'tag___' : init_list['hot_tags'][0] })

def tag_question(request):
  pass
