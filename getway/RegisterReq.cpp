#include <string>
#include <iostream>
using namespace std;

#include "RegisterReq.h"
#include "register.pb.h"


CRegisterReq::CRegisterReq()
{
	m_zmq_ctx = zmq_ctx_new();
	m_zmq_req = zmq_socket(m_zmq_ctx, ZMQ_REQ);
	zmq_connect(m_zmq_req, "tcp://127.0.0.1:5001");
	m_zmq_thread = zmq_threadstart(CRegisterReq::ThreadFun, this);
}


CRegisterReq::~CRegisterReq()
{
	zmq_threadclose(m_zmq_thread);
	zmq_close(m_zmq_req);
	zmq_ctx_term(m_zmq_ctx);
}

int CRegisterReq::Register(const REGISTER_REQ& req) const
{
	pbregister::MsgRegisterReq pbreq;
	pbreq.set_account(req.account);
	pbreq.set_passwd(req.passwd);

	string data;
	pbreq.SerializeToString(&data);
	zmq_msg_t zmsg;
	zmq_msg_init_size(&zmsg, data.size());
	memcpy(zmq_msg_data(&zmsg), data.c_str(), data.size());
	zmq_sendmsg(m_zmq_req, &zmsg, 0);
	return zmq_msg_close(&zmsg);
}

void CRegisterReq::ThreadFun(void* arg)
{
	CRegisterReq* p = reinterpret_cast<CRegisterReq*>(arg);
	while (true)
	{
		p->RecvData();
	}
}

int CRegisterReq::RecvData() const
{
	zmq_msg_t zmsg;
	zmq_msg_init(&zmsg);
	zmq_recvmsg(m_zmq_req, &zmsg, 0);

	pbregister::MsgRegisterRsp rsp;
	rsp.ParseFromArray(zmq_msg_data(&zmsg), zmq_msg_size(&zmsg));
	cout << "result:" << rsp.result() << "|";
	cout << "msg:" << rsp.msg() << endl;
	zmq_msg_close(&zmsg);
	return rsp.result();
}


