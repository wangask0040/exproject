#include "zmq.h"
#include <iostream>
#include <sstream>
using namespace std;

int main(int argc, char** argv)
{
	void* ctx = zmq_ctx_new();
	void* response = zmq_socket(ctx, ZMQ_REP);
	int ret = zmq_bind(response, "tcp://127.0.0.1:5001");
	cout << ret << endl;
	while (true)
	{
		char tmp[1024] = { 0 };
		int len = zmq_recv(response, tmp, sizeof(tmp), 0);
		cout << tmp << endl;
		stringstream ss;
		ss << "register" << '|' << len;
		zmq_send(response, ss.str().c_str(), ss.str().size(), 0);
	}
	return 1;
}

