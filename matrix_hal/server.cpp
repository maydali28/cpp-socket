#include "server.h"


namespace matrix_hal{

server::server(int port){
  this->port = port;
  address = "0.0.0.0";
}

server::server(int port,std::string address){
  this->port = port;
  this->address = address;
}
server::~server(){
  close();
}

int server::bind(){
  matrix_hal::socketAddr* sockaddr = new socketAddr(address,this->port);
  addr = sockaddr->to_sockaddr_in();

  socketfd = ::socket(AF_INET,SOCK_DGRAM,0);

  if(socketfd == -1){
    return errno;
  }
  int yes =1;
  if(::setsockopt(socketfd,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int)) != 0){
    close();
    return errno;
  }

  if(::bind(socketfd,(struct sockaddr *)&addr,sizeof(struct sockaddr))!= 0){
    close();
    return errno;
  }

  return 0;
}

matrix_hal::socketUDP* server::getConnexion(){
  return new matrix_hal::socketUDP(socketfd,addr);
}

void server::close(){
  if(socketfd == -1) return;
  ::close(socketfd);
}

bool server::valid(){
  return socketfd == -1;
}

int server::get_socket(){
  return socketfd;
}
}
