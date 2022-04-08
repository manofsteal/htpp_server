#include "HttpClient.h"

HttpClient::~HttpClient() {

}
HttpClient::HttpClient(std::shared_ptr<IOSocket> sock)
    : mSockClient(sock) {

}

Status HttpClient::handle(const Request& req, Reponse& res) {
    return Status::OK;
}

