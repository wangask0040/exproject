#include "RegisterReq.h"
#include <iostream>
using namespace std;


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
	req;
	int ret = zmq_connect(m_zmq_req, "tcp://127.0.0.1:5001");
	string str = "zxcz123asd";
	cout << ret << '|';
	ret = zmq_send(m_zmq_req, str.c_str(), str.size(), 0);
	char tmp[1024] = { 0 };
	cout << ret << '|';
	ret = zmq_recv(m_zmq_req, tmp, sizeof(tmp), 0);
	cout << ret << endl;
	return std::pair<int, string>(ret, string(tmp));
}


