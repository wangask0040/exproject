#include <event.h>
#include <event2/listener.h>
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

	event_base* base = event_base_new();
	sockaddr addr;
	int len = sizeof(addr);
	evutil_parse_sockaddr_port("127.0.0.1:5000", &addr, &len);
	evconnlistener*  listener =
		evconnlistener_new_bind(base, AcceptCB, nullptr, LEV_OPT_CLOSE_ON_FREE | LEV_OPT_REUSEABLE, 10, &addr, len);
	
	struct event *signal_event;
	signal_event = evsignal_new(base, SIGINT, nullptr, (void *)base);
	if (!signal_event || event_add(signal_event, NULL) < 0) {
		fprintf(stderr, "Could not create/add a signal event!\n");
		return 1;
	}

	event_base_dispatch(base);

	evconnlistener_free(listener);
	event_base_free(base);
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
}

void ReadCB(struct bufferevent *bev, void *ctx)
{
	ctx;
	evbuffer* evb =bufferevent_get_input(bev);
	size_t len = evbuffer_get_length(evb);
	if (len > 6)
	{
		char tmp[1024] = {0};
		bufferevent_read_buffer(bev, evb);
		evbuffer_remove(evb, tmp, sizeof(tmp));

		static CRegisterReq req;
		CRegisterReq::REGISTER_REQ st;
		st.account = tmp;
		st.passwd = "123456";
		std::pair<int, string> retpair = req.Register(st);

		evbuffer* p = bufferevent_get_output(bev);
		stringstream ss;
		ss << "asdadxzc" << '|' << len << '|' << retpair.first << '|' << retpair.second << endl;
		evbuffer_add(p, ss.str().c_str(), ss.str().length());
	}
}

void WriteCB(struct bufferevent *bev, void *ctx)
{
	bev;
	ctx;
	evbuffer* p = bufferevent_get_output(bev);
	cout << __FUNCTION__ << '|' << __LINE__ << '|' << evbuffer_get_length(p) << endl;
}

void EventCB(struct bufferevent *bev, short what, void *ctx)
{
	bev;
	ctx;
	cout << __FUNCTION__ << '|' << __LINE__ << '|' << what << endl;
	bufferevent_free(bev);
}
