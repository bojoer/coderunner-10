
#include "CodeRunner.h"
#include <protocol/TBinaryProtocol.h>
#include <server/TSimpleServer.h>
#include <transport/TServerSocket.h>
#include <transport/TBufferTransports.h>
#include<pwd.h>
#include <grp.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

int setUser(const char * username) {

    /* If we're root, try to become someone else. */
    if (getuid() == 0) {
        struct passwd* pwd = getpwnam(username);

        if (pwd == NULL) {
            fprintf(stderr, " unknown user - '%s'\n", username);
        }

        /* Set aux groups to null. */
        if (setgroups(0, NULL) < 0) {
            perror("setgroups - %m");
            exit(1);
        }
        /* Set primary group. */
        if (setgid(pwd->pw_gid) < 0) {
            //klog( LOG_CRIT, "setgid - %m" );
            exit(1);
        }

        /* Try setting aux groups correctly - not critical if this fails. */
        initgroups(username, pwd->pw_gid);
        /* Set uid. */
        if (setuid(pwd->pw_uid) < 0) {
            fprintf(stderr, " setuid - '%s'\n", username);
            exit(1);
        }
    }

    return 0;
}

int main(int argc, char **argv) {

    return 0;
    int port = 9090;
    shared_ptr<CodeRunner> handler(new CodeRunner(""));
    shared_ptr<TProcessor> processor(new CodeRunnerProcessor(handler));
    shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
    shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

    TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
    server.serve();
    return 0;
}
