#include"socketAddr.h"

namespace matrix_hal{
  socketAddr::socketAddr(struct sockaddr_in addr){
    port = addr.sin_port;
    address = inet_ntoa(addr.sin_addr);
  }

  socketAddr::socketAddr(std::string address, int port){
    this->address = address;
    this->port = port;
  }


  struct sockaddr_in socketAddr::to_sockaddr_in(){
    struct sockaddr_in addr;
    //addr = (struct sockaddr_in *) malloc(sizeof(struct sockaddr_in));
    memset(&addr,0,sizeof(addr));

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_aton(address.c_str(),&(addr.sin_addr));

    return addr;
  }

  int socketAddr::get_port(){
    return this->port;
  }

  std::string socketAddr::get_address(){
    return this->address;
  }

}
