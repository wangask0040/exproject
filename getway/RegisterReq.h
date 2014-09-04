#pragma once
#ifdef WIN32
#define ZMQ_HAVE_WINDOWS
#endif

#include "zmq.h"
#include "zmq_utils.h"


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
	int Register(const REGISTER_REQ& req) const;
	int RecvData() const;
	static void ThreadFun(void* arg);
private:
	void* m_zmq_ctx;
	void* m_zmq_req;
	void* m_zmq_thread;
};

