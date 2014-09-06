#include <event.h>
#include <event2/listener.h>
#include <evutil.h>
#include <sstream>
#include <iostream>
using namespace std;
#include <signal.h>
#include "RegisterReq.h"


void OnAccept(struct evconnlistener * p, evutil_socket_t fd, struct sockaddr * addr, int socklen, void * data);
void OnRead(struct bufferevent *bev, void *ctx);
void OnWrite(struct bufferevent *bev, void *ctx);
void OnEvent(struct bufferevent *bev, short what, void *ctx);
void OnTimer(evutil_socket_t fd, short what, void* ctx);

int main(int argc, char** argv)
{
	argc;
	argv;

#ifdef WIN32
	WSADATA wsa_data;
	WSAStartup(0x0201, &wsa_data);
#endif


	CRegisterReq rr;
	event_base* base = event_base_new();
	sockaddr addr;
	int len = sizeof(addr);
	evutil_parse_sockaddr_port("127.0.0.1:5000", &addr, &len);
	evconnlistener*  listener =
		evconnlistener_new_bind(base, OnAccept, &rr, LEV_OPT_CLOSE_ON_FREE | LEV_OPT_REUSEABLE, 10, &addr, len);

	event* evtime = nullptr;
	evtime = event_new(base, -1, EV_TIMEOUT | EV_PERSIST, OnTimer, &evtime);
	timeval tm;
	tm.tv_sec = 1;
	tm.tv_usec = 1;
	evtimer_add(evtime, &tm);

	event_base_dispatch(base);

	evtimer_del(evtime);
	evconnlistener_free(listener);
	event_base_free(base);
	
#ifdef WIN32
	WSACleanup();
#endif

	return 1;
}

void OnAccept(struct evconnlistener * p, evutil_socket_t fd, struct sockaddr * addr, int socklen, void * data)
{
	addr;
	socklen;
	event_base* base = evconnlistener_get_base(p);
	bufferevent* bev = bufferevent_socket_new(base, fd, BEV_OPT_CLOSE_ON_FREE);
	bufferevent_setcb(bev, OnRead, OnWrite, OnEvent, data);
	bufferevent_enable(bev, EV_WRITE | EV_READ);
	char bufaddr[128] = { 0 };
	evutil_inet_ntop(addr->sa_family, addr, bufaddr, sizeof(bufaddr));
	cout << "accept connection socket id = " << fd << "ipaddress =" << bufaddr << endl;
}

void OnRead(struct bufferevent *bev, void *ctx)
{
	CRegisterReq* q = reinterpret_cast<CRegisterReq*>(ctx);

	evbuffer* evinput = bufferevent_get_input(bev);

	char tmp[1024] = { 0 };
	bufferevent_read_buffer(bev, evinput);
	evbuffer_remove(evinput, tmp, sizeof(tmp));

	CRegisterReq::REGISTER_REQ st;
	st.account = tmp;
	st.passwd = "123456";
	
	int ret = q->Register(st);
	
	evbuffer* evoutput = bufferevent_get_output(bev);
	ret = q->RecvData(evoutput);
}

void OnWrite(struct bufferevent *bev, void *ctx)
{
	bev;
	ctx;
	cout << "into WriteCB" << endl;
}

void OnEvent(struct bufferevent *bev, short what, void *ctx)
{
	bev;
	ctx;
	cout << "into EventCB what = " << what << endl;
}

void OnTimer(evutil_socket_t fd, short what, void* ctx)
{
	fd; 
	what;
	ctx;
	cout << "into Ontimer what=" << what << endl;
}