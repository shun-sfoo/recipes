#pragma once

#include <functional>

namespace reactor {
// All client visible callbacks go here.
typedef std::function<void()> TimerCallback;
}  // namespace reactor
