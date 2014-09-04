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
		int len = 0;
		ret = zmq_recv(response, &len, sizeof(len), 0);
		cout << "ret:" << ret << "|len" << len << endl;
		if (ret > 0)
		{
			char* buf = new char[len];
			zmq_recv(response, buf, len, 0);
			pbregister::MsgRegisterReq req;
			req.ParseFromArray(buf, len);

			cout << req.account() << '|' << req.passwd() << endl;

			pbregister::MsgRegisterRsp rsp;
			rsp.set_msg("hello");
			rsp.set_result(-2); 
			string data;
			len = rsp.SerializePartialToString(&data);
			zmq_send(response, &len, sizeof(len), 0);
			zmq_send(response, data.c_str(), data.size(), 0);
			delete buf;
		}
	}
	return 1;
}

