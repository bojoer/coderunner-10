// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "CodeRunner.h"
#include <protocol/TBinaryProtocol.h>
#include <server/TSimpleServer.h>
#include <transport/TServerSocket.h>
#include <transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

class CodeRunnerHandler : virtual public CodeRunnerIf {
 public:
  CodeRunnerHandler() {
    // Your initialization goes here
  }

  void run(RunResult& _return, const CodePizza& pizza, const int32_t userid) {
    // Your implementation goes here
    printf("run\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<CodeRunnerHandler> handler(new CodeRunnerHandler());
  shared_ptr<TProcessor> processor(new CodeRunnerProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}
