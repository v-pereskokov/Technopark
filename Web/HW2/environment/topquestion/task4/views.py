from django.shortcuts import render
from django.http import HttpResponse
from django.views.decorators.csrf import csrf_exempt

@csrf_exempt
def get_post(request):
    response = "<p> GET/POST </p>" \
               "<form method='POST'>"\
               "<p><input type='text' name='text'></p>" \
               "<p><input type='submit' value='Send!'></p>" \
               "</form>"
    if request.method == 'GET':
        if request.GET:
            response += "<h3> <p> Get data: </p> </h3>"
            for key,value in request.GET.iteritems():
                if len(value) == 1:
                    response += "%s = %s <br>" % (key, value[0])
                else:
                    response += "%s = %s <br>" % (key, value)
    elif request.method == 'POST':
        response += "<h3> <p> Post data: </p> </h3>"
        response += "Value = %s <br>" % (request.POST.get('text'))
    return HttpResponse(response, content_type="text/html", status=200) 
