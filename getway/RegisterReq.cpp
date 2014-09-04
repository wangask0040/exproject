#include "RegisterReq.h"
#include <iostream>
using namespace std;


CRegisterReq::CRegisterReq()
{
	m_zmq_ctx = zmq_ctx_new();
}


CRegisterReq::~CRegisterReq()
{
	zmq_ctx_term(m_zmq_ctx);
}

std::pair<int, string> CRegisterReq::Register(const REGISTER_REQ& req) const
{
	req;
	void* request = zmq_socket(m_zmq_ctx, ZMQ_REQ);
	int ret = zmq_connect(request, "tcp://127.0.0.1:5001");
	string str = "zxcz123asd";
	cout << ret << '|';
	ret = zmq_send(request, str.c_str(), str.size(), 0);
	char tmp[1024] = { 0 };
	cout << ret << '|';
	ret = zmq_recv(request, tmp, sizeof(tmp), 0);
	cout << ret << endl;
	return std::pair<int, string>(ret, string(tmp));
}


