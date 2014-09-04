#pragma once
#ifdef WIN32
#define ZMQ_HAVE_WINDOWS
#endif

#include <zmq.h>
#include <zmq_utils.h>
#include <event.h>

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
	int RecvData(evbuffer* output) const;
	static void ThreadFun(void* arg);
private:
	void* m_zmq_ctx;
	void* m_zmq_socket_req;
};

