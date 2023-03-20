#include <muduo/base/Logging.h>
#include <muduo/net/EventLoop.h>
#include <unistd.h>

#include <echo.hpp>

// using namespace muduo;
// using namespace muduo::net;

int main() {
  LOG_INFO << "pid = " << getpid();
  muduo::net::EventLoop loop;
  muduo::net::InetAddress listenAddr(2007);
  EchoServer server(&loop, listenAddr);
  server.start();
  loop.loop();
}
