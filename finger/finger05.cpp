#include <muduo/net/EventLoop.h>
#include <muduo/net/TcpServer.h>

using namespace muduo;
using namespace muduo::net;

// 同finger04的安全问题

void onMessage(const TcpConnectionPtr &conn, Buffer *buf,
               Timestamp receiveTime) {
  if (buf->findCRLF()) {
    conn->send("No such user\r\n");  // 输出错误信息
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
