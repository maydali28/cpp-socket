#include "matrix_hal/server.h"
#include "matrix_hal/socketAddr.h"
#include "matrix_hal/socketUDP.h"
#include <iostream>
#include <string>
#include <cstring>
#include <valarray>

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

std::valarray<int16_t> raw_data_ = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
// matrix_hal::Datagram msg;
//    while (true) {
int tab[1024];
for(int i = 0;i<1024;i++){
tab[i] = 11111;
printf("%d\n",tab[i] );
}
  		socket->send("127.0.0.1",2012,raw_data_,raw_data_.size()) == 1 ? std::cout<<"ok"<<std::endl : std::cout<<"not ok"<<std::endl;
  		// std::cout<<msg.data<<std::endl;
//  }


}
