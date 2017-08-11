#include "matrix_hal/server.h"
#include "matrix_hal/socketAddr.h"
#include "matrix_hal/socketUDP.h"
#include <iostream>
#include <string>
#include <cstring>

int main(void){
  matrix_hal::server *srv = new matrix_hal::server(8080);
  int err = srv->bind();
  if(err != 0){
    std::cout<<strerror(err)<<std::endl;
    exit(err);
  }
  matrix_hal::socketUDP* socket = srv->getConnexion();
  if(!socket->valid()){
    delete socket;
    exit(0);
  }
// matrix_hal::Datagram msg;
//    while (true) {
  		socket->send("127.0.0.1",2012,"hello\n") == 1 ? std::cout<<"ok"<<std::endl : std::cout<<"not ok"<<std::endl;
  		// std::cout<<msg.data<<std::endl;
//  }


}
