#include <muduo/base/Thread.h>

#include <EventLoop.hpp>

reactor::EventLoop* g_loop;

void threadFunc() { g_loop->loop(); }

int main() {
  reactor::EventLoop loop;
  g_loop = &loop;
  muduo::Thread t(threadFunc);
  t.start();
  t.join();
}
