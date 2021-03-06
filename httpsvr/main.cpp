#include <evhttp.h>
#include <iostream>
using namespace std;

#include "libprotocol/http.pb.h"


void http_route(evhttp* http);
void request_cb_test(struct evhttp_request *req, void *arg);
const char* translation_cmdtype(const evhttp_request* req);
void send_document_cb(struct evhttp_request *req, void *arg);

int main(int argc, char** argv)
{
#ifdef WIN32
	WSADATA wsa_data;
	WSAStartup(0x0201, &wsa_data);
#endif

	event_base* base = event_base_new();
	evhttp* http = evhttp_new(base);

	http_route(http);

	evhttp_bound_socket* handle;
	handle = evhttp_bind_socket_with_handle(http, argv[1], strtoul(argv[2], nullptr, 0));

	event_base_dispatch(base);

	evhttp_free(http);
	event_base_free(base);

#ifdef WIN32
	WSACleanup();
#endif
	return 1;
}

void http_route(evhttp* http)
{
	evhttp_set_cb(http, "/test", request_cb_test, nullptr);
	evhttp_set_gencb(http, send_document_cb, nullptr);
}

void request_cb_test(struct evhttp_request *req, void *arg)
{
	cout << translation_cmdtype(req) << endl;

	if (evhttp_request_get_command(req) == EVHTTP_REQ_POST)
	{
		if (req->body_size > 0)
		{
			size_t inputlen = evbuffer_get_length(req->input_buffer);
			char tmp[1024];
			evbuffer_copyout(req->input_buffer, tmp, req->body_size);
			http::MsgHttpReq msg;
			msg.ParseFromArray(tmp, req->body_size);
		}
	}

	evbuffer* output = evbuffer_new();
	char ar[100] = "zczxczxczxc\r\n";
	evbuffer_add(output, ar, sizeof(ar));
	evhttp_send_reply(req, 200, "OK", output);
	evbuffer_free(output);
}

const char* translation_cmdtype(const evhttp_request* req)
{
	switch (evhttp_request_get_command(req)) {
	case EVHTTP_REQ_GET: return"GET"; break;
	case EVHTTP_REQ_POST: return"POST"; break;
	case EVHTTP_REQ_HEAD: return"HEAD"; break;
	case EVHTTP_REQ_PUT: return"PUT"; break;
	case EVHTTP_REQ_DELETE: return"DELETE"; break;
	case EVHTTP_REQ_OPTIONS: return"OPTIONS"; break;
	case EVHTTP_REQ_TRACE: return"TRACE"; break;
	case EVHTTP_REQ_CONNECT: return"CONNECT"; break;
	case EVHTTP_REQ_PATCH: return"PATCH"; break;
	default: return"unknown"; break;
	}
}

void send_document_cb(struct evhttp_request *req, void *arg)
{
	cout << "not find this cmd:" << evhttp_request_get_uri(req) << endl;
	evbuffer* output = evbuffer_new();
	char ar[100] = "url error\r\n";
	evbuffer_add(output, ar, sizeof(ar));
	evhttp_send_reply(req, 200, "OK", output);
	evbuffer_free(output);
}

void GetUrlParamValue(evhttp_request* req, const char* param_name, std::string& param_value)
{
	const char* url = evhttp_request_get_uri(req);
	if (url != nullptr)
	{
		evkeyvalq* http_query = nullptr;
		if (evhttp_parse_query_str(url, http_query) == 0)
		{
			const char* tmp = evhttp_find_header(http_query, param_name);
			param_value = tmp;
			evhttp_clear_headers(http_query);
		}
	}
}
