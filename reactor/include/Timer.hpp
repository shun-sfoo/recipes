#pragma once

#include <muduo/base/Timestamp.h>

#include "Callbacks.hpp"
namespace reactor {
class Timer {
 public:
  Timer(const TimerCallback& cb, muduo::Timestamp when, double interval)
      : callbacks_(cb),
        expiration_(when),
        interval_(interval),
        repeat_(interval_ > 0.0) {}

  void run() const { callbacks_(); }

  muduo::Timestamp expiration() const { return expiration_; }

  bool repeat() const { return repeat_; }

  void restart(muduo::Timestamp now);

 private:
  const TimerCallback callbacks_;
  muduo::Timestamp expiration_;
  const double interval_;
  const bool repeat_;
};

}  // namespace reactor
