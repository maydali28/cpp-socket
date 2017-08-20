#ifndef SOCKETUPD_H_
#define  SOCKETUPD_H_

#include"socketAddr.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <cerrno>
#include <string>
#include <fcntl.h>
#include <valarray>
#include <iostream>
#include <iterator>
#include <ostream>
#include <sstream>

#define MAX_BUFFER 1024

namespace matrix_hal{
	typedef std::string Data;
	typedef struct
	{
			struct sockaddr_in address;
			Data data;
	}Datagram;

		class socketUDP{
    public:
			socketUDP(int socket,struct sockaddr_in addr);
			~socketUDP();
			void close();
			bool valid();
			int get_socket();
			socketAddr* get_socketAddr();
			Datagram receive();
			int send(std::string data);
			int send(std::string ip,std::string data);
			int send(std::string ip, int port,std::string data);
			int send(std::string ip, int port,std::valarray<int16_t> buf, int length);
	private:
		int socketfd;
        struct sockaddr_in address;
        socketAddr* sockaddr;
	};

};

#endif // SOCKETUPD_H_
