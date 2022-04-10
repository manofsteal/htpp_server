#include "IOSocketSrv.h"

#include <unistd.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <sys/types.h>
#include <sys/socket.h>



IOSocketSrv::~IOSocketSrv() {

}

IOSocketSrv::IOSocketSrv(std::string host, std::uint16_t port) 
    : mHost(host), mPort(port)
{

}


Status IOSocketSrv::setup() {

  int opt = 1;
  sockaddr_in server_address;


  if ((mSockFD = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0)) < 0) {
    return Status::N_OK;
  }

  if (setsockopt(mSockFD, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
    return Status::N_OK;
  }
  

  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  inet_pton(AF_INET, mHost.c_str(), &(server_address.sin_addr.s_addr));
  server_address.sin_port = htons(mPort);

  if (::bind(mSockFD, (sockaddr *)&server_address, sizeof(server_address)) < 0) {
    return Status::N_OK;
  }

  if (::listen(mSockFD, Const::BacklogSize) < 0) {
    return Status::N_OK;
  }

  return Status::OK;
}

std::optional<os::FileDesc> IOSocketSrv::listen() {

    sockaddr_in client_address;
    socklen_t client_len = sizeof(client_address);

    auto clientFD = ::accept4(mSockFD, (sockaddr *)&client_address, &client_len, SOCK_NONBLOCK);

    if (clientFD < 0) return {};

    return std::optional<os::FileDesc>(clientFD);

}
