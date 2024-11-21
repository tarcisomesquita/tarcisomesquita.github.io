#!/usr/bin/python3
from http import server

class MyHTTPRequestHandler(server.SimpleHTTPRequestHandler):
    def end_headers(self):
        self.send_my_headers()

        server.SimpleHTTPRequestHandler.end_headers(self)

    def send_my_headers(self):
        self.send_header("Access-Control-Allow-Origin", "*")


if __name__ == '__main__':
    server.test(HandlerClass=MyHTTPRequestHandler)


# see https://docs.python.org/3/library/http.server.html

#import SimpleHTTPServer
#import SocketServer
#PORT = 9999

#def do_GET(self):
#    self.send_response(200)
#    self.send_header('Access-Control-Allow-Origin', 'http://example.com')           
#    self.end_headers()

#Handler = SimpleHTTPServer.SimpleHTTPRequestHandler
#Handler.do_GET = do_GET
#httpd = SocketServer.TCPServer(("", PORT), Handler)
#httpd.serve_forever()

