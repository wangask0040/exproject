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
		zmq_msg_t zmsg;
		zmq_msg_init(&zmsg);
		zmq_recvmsg(response, &zmsg, 0);

		pbregister::MsgRegisterReq req;
		req.ParseFromArray(zmq_msg_data(&zmsg), zmq_msg_size(&zmsg));
		cout << __FUNCTION__ << "|accout:" << req.account() << "|passwd:" << req.passwd() << endl;
		zmq_msg_close(&zmsg);

		pbregister::MsgRegisterRsp rsp;
		rsp.set_msg("register return");
		rsp.set_result(-2); 

		zmq_msg_t zmsgsend;
		string data;
		rsp.SerializeToString(&data);
		zmq_msg_init_size(&zmsgsend, data.size());
		memcpy(zmq_msg_data(&zmsgsend), data.c_str(), data.size());
		zmq_sendmsg(response, &zmsgsend, 0);
		zmq_msg_close(&zmsgsend);
	}

	return 1;
}

