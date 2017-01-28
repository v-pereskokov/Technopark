from django.core.paginator import Paginator, EmptyPage, PageNotAnInteger

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

def pagination(request):
  init_list = init()
  paginator = Paginator(init_list['questions'], 4)
  page = request.GET.get('page')
  try:
    qs = paginator.page(page)
  except PageNotAnInteger:
    qs = paginator.page(1)
  except EmptyPage:
    qs = paginator.page(paginator.num_pages)
  return qs
