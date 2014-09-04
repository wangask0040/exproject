#include <string>
#include <iostream>
using namespace std;

#include "RegisterReq.h"
#include "register.pb.h"


CRegisterReq::CRegisterReq()
{
	m_zmq_ctx = zmq_ctx_new();
	m_zmq_socket_req = zmq_socket(m_zmq_ctx, ZMQ_REQ);
	zmq_connect(m_zmq_socket_req, "tcp://127.0.0.1:5001");
}


CRegisterReq::~CRegisterReq()
{
	zmq_close(m_zmq_socket_req);
	zmq_ctx_term(m_zmq_ctx);
}

int CRegisterReq::Register(const REGISTER_REQ& req) const
{
	cout << "into Register account = " << req.account << " passwd =" << req.passwd << endl;
	pbregister::MsgRegisterReq pbreq;
	pbreq.set_account(req.account);
	pbreq.set_passwd(req.passwd);

	string data;
	pbreq.SerializeToString(&data);
	zmq_msg_t zmsg;
	zmq_msg_init_size(&zmsg, data.size());
	memcpy(zmq_msg_data(&zmsg), data.c_str(), data.size());
	zmq_sendmsg(m_zmq_socket_req, &zmsg, 0);
	return zmq_msg_close(&zmsg);
}

void CRegisterReq::ThreadFun(void* arg)
{
	arg;
}

int CRegisterReq::RecvData(evbuffer* output) const
{
	zmq_msg_t zmsg;
	zmq_msg_init(&zmsg);
	zmq_recvmsg(m_zmq_socket_req, &zmsg, 0);

	pbregister::MsgRegisterRsp rsp;
	rsp.ParseFromArray(zmq_msg_data(&zmsg), zmq_msg_size(&zmsg));

	cout << "into RecvData result=" << rsp.result() << " msg=" << rsp.msg() << endl;

	zmq_msg_close(&zmsg);
	string str = "register success\n";
	evbuffer_add(output, str.c_str(), str.size());
	return 1;
}


