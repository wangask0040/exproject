#include "RegisterReq.h"
#include <iostream>
using namespace std;

#include "register.pb.h"

CRegisterReq::CRegisterReq()
{
	m_zmq_ctx = zmq_ctx_new();
	m_zmq_req = zmq_socket(m_zmq_ctx, ZMQ_REQ);
}


CRegisterReq::~CRegisterReq()
{
	zmq_close(m_zmq_req);
	zmq_ctx_term(m_zmq_ctx);
}

std::pair<int, string> CRegisterReq::Register(const REGISTER_REQ& req) const
{
	int ret = zmq_connect(m_zmq_req, "tcp://127.0.0.1:5001");
	cout << ret << '|';
	pbregister::MsgRegisterReq pbreq;
	pbreq.set_account(req.account);
	pbreq.set_passwd(req.passwd);

	string data;
	pbreq.SerializeToString(&data);
	zmq_send(m_zmq_req, data.c_str(), data.size(), 0);

	char tmp[1024] = { 0 };
	int len = zmq_recv(m_zmq_req, tmp, sizeof(tmp), 0);
	pbregister::MsgRegisterRsp rsp;
	rsp.ParseFromArray(tmp, len);
	cout << rsp.result() << '|' << rsp.msg() << endl;

	return std::pair<int, string>(ret, string("raeqwe"));
}


