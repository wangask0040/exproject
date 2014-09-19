import http_pb2
import httplib

body = http_pb2.MsgHttpReq()
body.account = 3
body.passwd = 'bcvnvbnn'
data = body.SerializeToString()

connection = httplib.HTTPConnection('192.168.1.104', 8001)
connection.connect()
connection.request('POST', '/test', data, {
       "Content-Type": "application/json"
     })


