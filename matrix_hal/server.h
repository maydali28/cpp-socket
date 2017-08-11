#ifndef SERVER_H_
#define SERVER_H_

#include "socketAddr.h"
#include "socketUDP.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <cerrno>

namespace matrix_hal{
class server{
public:
  server(int port);
  server(int port,std::string address);
  ~server();
  int bind();
  void close();
  bool valid();
  int get_socket();
  socketUDP* getConnexion();
private:
  std::string address;
  int port;
  int socketfd;
  struct sockaddr_in addr;

};
};
#endif // SERVER_H_
