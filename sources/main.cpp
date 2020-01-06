
#include "server.hpp"
#include "client.hpp"

int main(int argc, char* argv[]) {
    init();
    Server server;
    Client client;
    client.work();
}
