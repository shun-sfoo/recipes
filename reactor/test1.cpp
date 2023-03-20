#include <pthread.h>
#include <unistd.h>

#include <EventLoop.hpp>

void threadFunc() {
  printf("threadFunc(): pid = %d, tid = %d\n", getpid(),
         muduo::CurrentThread::tid());
  reactor::EventLoop loop;
  loop.loop();
}

int main() {
  printf("main(): pid = %d, tid = %d\n", getpid(), muduo::CurrentThread::tid());

  reactor::EventLoop loop;

  muduo::Thread thread(threadFunc);
  thread.start();

  loop.loop();
  pthread_exit(NULL);
}
