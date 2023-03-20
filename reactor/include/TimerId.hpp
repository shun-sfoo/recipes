#pragma once
#include "copyable.hpp"
namespace reactor {
class Timer;

class TimerId : public copyable {
 public:
  explicit TimerId(Timer* timer) : value_(timer) {}

 private:
  Timer* value_;
};
}  // namespace reactor
