#include <muduo/net/EventLoop.h>
#include <muduo/net/TcpServer.h>
#include <unistd.h>

#include <map>

using namespace muduo;
using namespace muduo::net;

// 同finger04的安全问题

typedef std::map<string, string> UserMap;
UserMap users;

string getUser(const string &user) {
  string result = "No such user";
  UserMap::iterator it = users.find(user);
  if (it != users.end()) {
    result = it->second;
  }

  return result;
}

void onMessage(const TcpConnectionPtr &conn, Buffer *buf,
               Timestamp receiveTime) {
  const char *crlf = buf->findCRLF();
  if (crlf) {
    string user(buf->peek(), crlf);
    conn->send(getUser(user) + "\r\n");
    buf->retrieveUntil(crlf + 2);
    conn->shutdown();
  }

  if (buf->findCRLF()) {
    conn->send("No such user\r\n");
    conn->shutdown();
  }
}

int main() {
  EventLoop loop;
  TcpServer server(&loop, InetAddress(1079), "Finger");
  server.setMessageCallback(onMessage);
  server.start();
  loop.loop();
}
