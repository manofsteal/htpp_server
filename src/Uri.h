// Define object that can be used to represent a Unique Resource Identifier
// which is useful for parsing and request handling

#ifndef URI_H_
#define URI_H_

#include <algorithm>
#include <cctype>
#include <string>
#include <utility>


class Uri {
public:
  Uri() = default;
  explicit Uri(const std::string& path) : mPath(path) {
    setPathToLowercase();
  }
  ~Uri() = default;

  inline bool operator<(const Uri& other) const { return mPath < other.mPath; }
  inline bool operator==(const Uri& other) const { return mPath == other.mPath; }

  void setPath(std::string path) {
    mPath = std::move(path);
    setPathToLowercase();
  }

  std::string scheme() const { return mScheme; }
  std::string host() const { return mHost; }
  std::uint16_t port() const { return mPort; }
  std::string path() const { return mPath; }

private:
  // Only the path is supported for now
  std::string mPath;
  std::string mScheme;
  std::string mHost;
  std::uint16_t mPort;

  void setPathToLowercase() {
    std::transform(mPath.begin(), mPath.end(), mPath.begin(), [](char c) { return tolower(c); });
  }
};


#endif  // URI_H_

