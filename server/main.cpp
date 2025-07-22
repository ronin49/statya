#include "gen-cpp/TaskService.h"
#include <thrift/transport/TSimpleFileTransport.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/server/TThreadedServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TBinaryProtocol.h>

#include "db.h"

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;
using namespace TaskService;

class TaskServiceHandler : public TaskServiceIf {
	public:
		TaskServiceHandler() {}

		void getTaskById(Task& _return, const int32_t id) override {
			// _return.id = id;
			// _return.title = "Example Task";
			// _return.status = "To Do";
		}

		void addTask(const Task& t) override {
			// printf("Task received: %d - %s\n", t.id, t.title.c_str());
			try {
			add_task(t.title,t.description);
			} catch (...){}
		}
};

int main() {
	int port = 9090;
	::std::shared_ptr<TaskServiceHandler> handler(new TaskServiceHandler());
	::std::shared_ptr<TProcessor> processor(new TaskServiceProcessor(handler));
	::std::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
	::std::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
	::std::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

	TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
	printf("Starting the server on port %d...\n", port);
	server.serve();
	return 0;
}

