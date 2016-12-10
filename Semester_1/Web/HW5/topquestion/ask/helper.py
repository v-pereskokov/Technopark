from django.core.paginator import Paginator, EmptyPage, PageNotAnInteger
from ask.models import *
import numpy as np


def pagination(request, data, count, page):
  paginator = Paginator(data, count)
  get = request.GET.get('page')
  if get:
    page = int(get)
  try: 
    paginator_datas_list = paginator.page(int(page))
  except PageNotAnInteger: 
    data_list = paginator.page(1)
  except EmptyPage:
    paginator_datas_list = paginator.page(paginator.num_pages)
  return paginator_datas_list


def randomTags(Tag):
	tags = []
	for i in range(Tag.objects.count()):
		tags.append(str(Tag.objects.get_queryset()[i]))
	np.random.shuffle(tags)
	return tags[:3]
