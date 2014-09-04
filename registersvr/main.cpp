#include "zmq.h"
#include <iostream>
#include <sstream>
using namespace std;

#include "register.pb.h"

int main(int argc, char** argv)
{
	void* ctx = zmq_ctx_new();
	void* response = zmq_socket(ctx, ZMQ_REP);
	int ret = zmq_bind(response, "tcp://127.0.0.1:5001");
	while (true)
	{
		char buf[1024] = { 0 };
		int len = zmq_recv(response, buf, sizeof(buf), 0);
		pbregister::MsgRegisterReq req;
		req.ParseFromArray(buf, len);

		cout << req.account() << '|' << req.passwd() << endl;

		pbregister::MsgRegisterRsp rsp;
		rsp.set_msg("hello");
		rsp.set_result(-2); 
		string data;
		rsp.SerializeToString(&data);
		zmq_send(response, data.c_str(), data.size(), 0);
	}

	return 1;
}

