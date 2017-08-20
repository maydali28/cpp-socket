#include "socketUDP.h"

namespace matrix_hal{

socketUDP::socketUDP(int socket,struct sockaddr_in addr){
  this->socketfd = socket;
  this->address = addr;
  this->sockaddr = new socketAddr(addr);
}

socketUDP::~socketUDP(){
    delete sockaddr;
    close();
}

void socketUDP::close(){
  if(socketfd == -1) return;
  ::close(socketfd);
}

bool socketUDP::valid(){
  return socketfd != -1;
}

int socketUDP::get_socket(){
  return socketfd;
}

socketAddr* socketUDP::get_socketAddr(){
  return sockaddr;
}

Datagram socketUDP::receive(){
    socklen_t size = sizeof(struct sockaddr_in);
    char * Buffer = (char*) malloc(MAX_BUFFER*sizeof(char));
    struct sockaddr_in addressClt;
    Datagram ret;
    if(::recvfrom(socketfd,Buffer,sizeof(Buffer),0,(struct sockaddr *) &addressClt,&size)){
      ret.data = Buffer;
      ret.address = addressClt;
      free(Buffer);
    }
    return ret;
}

int socketUDP::send(std::string data){
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = (this->address).sin_port;
    address.sin_addr = (this->address).sin_addr;
    if (sendto(this->socketfd, (void*)data.c_str(), data.length() + 1, 0, (struct sockaddr*)&address, sizeof(struct sockaddr_in)) == -1)
    {
        return 0;
    }
    return 1;
}

int socketUDP::send(std::string ip,std::string data){
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = (this->address).sin_port;
    inet_aton(ip.c_str(), &address.sin_addr);
    if (sendto(this->socketfd, (void*)data.c_str(), data.length() + 1, 0, (struct sockaddr*)&address, sizeof(struct sockaddr_in)) == -1)
    {
        return 0;
    }
    return 1;
}

int socketUDP::send(std::string ip, int port, std::string data){
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    inet_aton(ip.c_str(), &address.sin_addr);
    if (sendto(this->socketfd, (void*)data.c_str(), data.length() + 1, 0, (struct sockaddr*)&address, sizeof(struct sockaddr_in)) == -1)
    {
        return 0;
    }
    return 1;
}

int socketUDP::send(std::string ip, int port,std::valarray<int16_t> buf, int length){
      std::ostringstream oss;
      if (buf.size())
      {
        // Convert all but the last element to avoid a trailing ","
        std::copy(std::begin(buf), std::end(buf)-1,
            std::ostream_iterator<int16_t>(oss, ","));

        // Now add the last element with no delimiter
        oss << buf[buf.size()-1 ];
      }
      std::cout << oss.str() <<"\n";
      std::string packet = oss.str();
      int result = send(ip,port, packet);
      return result;
}

}
