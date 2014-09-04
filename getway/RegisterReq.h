#pragma once
#include <string>
#include "zmq.h"
using namespace std;

class CRegisterReq
{
public:

	struct REGISTER_REQ
	{
		string account;
		string passwd;
	};

	CRegisterReq();
	~CRegisterReq();
	std::pair<int, string> Register(const REGISTER_REQ& req) const;

private:
	void* m_zmq_ctx;
};

