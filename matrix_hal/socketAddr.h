#ifndef SOCKETADDR_H_
#define SOCKETADDR_H_

#include<netinet/in.h>
#include<arpa/inet.h>
#include<string>
#include<cstring>

namespace matrix_hal{

  class socketAddr{

  public:
    socketAddr(struct sockaddr_in addr);
    socketAddr(std::string address, int port);
    struct sockaddr_in to_sockaddr_in();
    int get_port();
    std::string get_address();

  private:
    std::string address;
    int port;
  };
};
#endif //SOCKETADDR_H_
