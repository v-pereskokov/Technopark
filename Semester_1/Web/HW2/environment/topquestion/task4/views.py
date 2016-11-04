from django.shortcuts import render

# Create your views here.
from django.http import HttpResponse

def get_post(request):
  print(request.GET)
  return HttpResponse(request.GET)
