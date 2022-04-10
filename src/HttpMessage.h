// Defines objects that represents HTTP request and response
// and some utility functions to manipulate HTTP data

#ifndef HTTP_MESSAGE_H_
#define HTTP_MESSAGE_H_

#include <map>
#include <string>
#include <utility>
#include <optional>

#include "Uri.h"


// HTTP methods defined in the following document:
// https://developer.mozilla.org/en-US/docs/Web/HTTP/Methods
enum class HttpMethod {
  GET,
  HEAD,
  POST,
  PUT,
  DELETE,
  CONNECT,
  OPTIONS,
  TRACE,
  PATCH
};

// Here we only support HTTP/1.1
enum class HttpVersion {
  HTTP_0_9 = 9,
  HTTP_1_0 = 10,
  HTTP_1_1 = 11,
  HTTP_2_0 = 20
};

// HTTP response status codes as listed in:
// https://developer.mozilla.org/en-US/docs/Web/HTTP/Status
// Note that not all of them are present in this enum class
enum class HttpStatusCode {
  Continue = 100,
  SwitchingProtocols = 101,
  EarlyHints = 103,
  Ok = 200,
  Created = 201,
  Accepted = 202,
  NonAuthoritativeInformation = 203,
  NoContent = 204,
  ResetContent = 205,
  PartialContent = 206,
  MultipleChoices = 300,
  MovedPermanently = 301,
  Found = 302,
  NotModified = 304,
  BadRequest = 400,
  Unauthorized = 401,
  Forbidden = 403,
  NotFound = 404,
  MethodNotAllowed = 405,
  RequestTimeout = 408,
  ImATeapot = 418,
  InternalServerError = 500,
  NotImplemented = 501,
  BadGateway = 502,
  ServiceUnvailable = 503,
  GatewayTimeout = 504,
  HttpVersionNotSupported = 505
};


// Defines the common interface of an HTTP request and HTTP response.
// Each message will have an HTTP version, collection of header fields,
// and message content. The collection of headers and content can be empty.

class HttpMessageCommon {
public:
  HttpMessageCommon() : mVersion(HttpVersion::HTTP_1_1) {}
  virtual ~HttpMessageCommon() = default;

  void setHeader(const std::string& key, const std::string& value) { mHeaders[key] = std::move(value); }
  void removeHeader(const std::string& key) { mHeaders.erase(key); }
  void clearHeader() { mHeaders.clear(); }
  void setContent(const std::string& content) {
    mContent = std::move(content);
    setContentLength();
  }
  void clearContent(const std::string& content) {
    mContent.clear();
    setContentLength();
  }

  HttpVersion version () const { return mVersion; }
  std::string header(const std::string& key) const {
    if (mHeaders.count(key) > 0)
      return mHeaders.at(key);
    return std::string();
  }
  std::map<std::string, std::string> headers() const { return mHeaders; }
  std::string content() const { return mContent; }
  size_t contentLength() const { return mContent.length(); }

protected:
  HttpVersion mVersion;
  std::map<std::string, std::string> mHeaders;
  std::string mContent;

  void setContentLength() { setHeader("Content-Length", std::to_string(mContent.length())); }
};

// An HttpRequest object represents a single HTTP request
// It has a HTTP method and URI so that the server can identify
// the corresponding resource and action
class HttpRequest : public HttpMessageCommon {
public:
  HttpRequest() : mMethod(HttpMethod::GET) {}
  ~HttpRequest() = default;

  void setMethod(HttpMethod method) { mMethod = method; }
  void setUri(const Uri& uri) { mUri = std::move(uri); }
   
  void setCode(HttpStatusCode code) { mCode = std::optional<HttpStatusCode>(code);}

  HttpMethod method() const { return mMethod; }
  Uri uri() const { return mUri; }
  std::optional<HttpStatusCode> code() const { return mCode; };

  friend std::string toString(const HttpRequest& request);
  friend HttpRequest toReq(const std::string& request_string);


private:
  HttpMethod mMethod;
  Uri mUri;
  std::optional<HttpStatusCode> mCode;
};

// An HTTPResponse object represents a single HTTP response
// The HTTP server sends an HTTP response to a client that include
// an HTTP status code, headers, and (optional) content
class HttpResponse : public HttpMessageCommon {
public:
  HttpResponse() : mStatusCode(HttpStatusCode::Ok) {}
  HttpResponse(HttpStatusCode statusCode) : mStatusCode(statusCode) {}
  ~HttpResponse() = default;

  void setStatusCode(HttpStatusCode statusCode) { mStatusCode = statusCode; }

  HttpStatusCode statusCode() const { return mStatusCode; }

  friend std::string toString(const HttpResponse& request, bool sendContent = true);
  friend HttpResponse fromString(const std::string& responseString);

private:
  HttpStatusCode mStatusCode;
};

namespace utils {


    std::string MethodToString(HttpMethod method);
    std::string VersionToString(HttpVersion version);
    std::string CodeToString(HttpStatusCode status_code);
  
    std::string ReqToString(const HttpRequest& request);
    std::string ResToString(const HttpResponse& response, bool sendContent);
    
    std::optional<HttpMethod> MethodFromString(const std::string& mMethodstring);
    std::optional<HttpVersion> VersionFromString(const std::string& mVersionstring);

    HttpRequest ReqFromString(const std::string& requestString);
    HttpResponse ResFromString(const std::string& responseString);
}


#endif  // HTTP_MESSAGE_H_

