#pragma once

#include <muduo/base/Timestamp.h>

#include <EventLoop.hpp>
#include <map>
#include <noncopyable.hpp>
#include <vector>

struct pollfd;

namespace reactor {
class Channel;

class Poller : noncopyable {
 public:
  typedef std::vector<Channel*> ChannelList;

  Poller(EventLoop* loop);
  ~Poller();

  muduo::Timestamp poll(int timeoutMs, ChannelList* activeChannels);

  void updateChannel(Channel* channel);

  void assertInLoopThread() { ownerLoop_->assertInLoopThread(); }

 private:
  void fillActiveChannels(int numEvents, ChannelList* activeChannels) const;

  typedef std::vector<struct pollfd> PollFdList;
  typedef std::map<int, Channel*> ChannelMap;

  EventLoop* ownerLoop_;
  PollFdList pollfds_;
  ChannelMap channels_;
};

}  // namespace reactor
