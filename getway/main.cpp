#include <event.h>
#include <event2/listener.h>
#include <evutil.h>
#include <sstream>
#include <iostream>
using namespace std;
#include <signal.h>
#include "RegisterReq.h"


void AcceptCB(struct evconnlistener * p, evutil_socket_t fd, struct sockaddr * addr, int socklen, void * data);
void ReadCB(struct bufferevent *bev, void *ctx);
void WriteCB(struct bufferevent *bev, void *ctx);
void EventCB(struct bufferevent *bev, short what, void *ctx);

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
		evconnlistener_new_bind(base, AcceptCB, &rr, LEV_OPT_CLOSE_ON_FREE | LEV_OPT_REUSEABLE, 10, &addr, len);

	struct event *signal_event;
	signal_event = evsignal_new(base, SIGINT, nullptr, (void *)base);
	if (!signal_event || event_add(signal_event, NULL) < 0) {
		fprintf(stderr, "Could not create/add a signal event!\n");
		return 1;
	}

	event_base_dispatch(base);

	evconnlistener_free(listener);
	event_base_free(base);
	
#ifdef WIN32
	WSACleanup();
#endif

	return 1;
}

void AcceptCB(struct evconnlistener * p, evutil_socket_t fd, struct sockaddr * addr, int socklen, void * data)
{
	addr;
	socklen;
	event_base* base = evconnlistener_get_base(p);
	bufferevent* bev = bufferevent_socket_new(base, fd, BEV_OPT_CLOSE_ON_FREE);
	bufferevent_setcb(bev, ReadCB, WriteCB, EventCB, data);
	bufferevent_enable(bev, EV_WRITE | EV_READ);
	char bufaddr[128] = { 0 };
	evutil_inet_ntop(addr->sa_family, addr, bufaddr, sizeof(bufaddr));
	cout << "accept connection socket id = " << fd << "ipaddress =" << bufaddr << endl;
}

void ReadCB(struct bufferevent *bev, void *ctx)
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

void WriteCB(struct bufferevent *bev, void *ctx)
{
	bev;
	ctx;
	cout << "into WriteCB" << endl;
}

void EventCB(struct bufferevent *bev, short what, void *ctx)
{
	bev;
	ctx;
	cout << "into EventCB what = " << what << endl;
}
