from django.shortcuts import render_to_response

def index(request):
  return render_to_response('new_index.html', {'isLogging' : None})

