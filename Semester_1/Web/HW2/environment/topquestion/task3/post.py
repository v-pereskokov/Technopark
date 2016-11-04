from pprint import pformat
from cgi import parse_qsl, escape

def application(environ, start_response):
    output = b''
    d = parse_qsl(environ['QUERY_STRING'])
    if environ['REQUEST_METHOD'] == 'POST':
        output += pformat(environ['wsgi.input'].read())
        print(pformat(environ['wsgi.input'].read()))

    if environ['REQUEST_METHOD'] == 'GET':
        if environ['QUERY_STRING'] != '':
            for ch in d:
                print(ch)
                output += str(ch)

    start_response('200 OK', [('Content-type', 'text/html')])
    return output

