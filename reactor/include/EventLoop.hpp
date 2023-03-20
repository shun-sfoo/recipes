#pragma once
#include <muduo/base/Thread.h>
#include <sys/types.h>

#include <memory>
#include <noncopyable.hpp>
#include <vector>

namespace reactor {
class Channel;
class Poller;
class EventLoop : noncopyable {
 public:
  EventLoop();
  ~EventLoop();

  void loop();
  void quit();
  void updateChannel(Channel* channel);

  void assertInLoopThread() {
    if (!isInLoopThread()) {
      abortNotInLoopThread();
    }
  }

  bool isInLoopThread() const {
    return threadId_ == muduo::CurrentThread::tid();
  }

 private:
  void abortNotInLoopThread();

  typedef std::vector<Channel*> ChannelList;

  bool looping_;  // atomic
  bool quit_;     // atomic
  const pid_t threadId_;
  std::unique_ptr<Poller> poller_;
  ChannelList activeChannels_;
};
}  // namespace reactor
