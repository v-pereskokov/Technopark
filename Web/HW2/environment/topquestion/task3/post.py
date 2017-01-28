from pprint import pformat
from cgi import parse_qsl, escape

def application(environ, start_response):
    output = ["<p> GET/POST </p>",
              "<form method='POST'>",
              "<p><input type='text' name='text'></p>",
              "<p><input type='submit' value='Send!'></p>",
              "</form>"]
    response_headers = [('Content-type','text/html')]
    if environ['REQUEST_METHOD'] == "GET":
        dict_value = parse_qsl(environ['QUERY_STRING'])
        output.append("<h3> <p> Get data: </p> </h3>")
        for key,value in dict_value:
            if len(value) == 1:
                output.append("%s = %s <br>" % (key, value[0]))
            else:
                output.append("%s = %s <br>" % (key, value))
    else:
        try:
            size = int(environ.get('CONTENT_LENGTH', 0))
        except:
            size = 0
        request=environ['wsgi.input'].read(size)
        dict_value = dict(parse_qsl(request))
        output.append("<h3> <p> Post data: </p> </h3>")
        output.append("Value = %s <br>" % (dict_value['text']))
    response_headers.append(('Content-length',str(sum([len(x) for x in output]))))
    start_response('200 OK',response_headers)
    return output
