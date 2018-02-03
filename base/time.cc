#include "base/time.h"

// String formatting
std::ostream& operator<<(std::ostream& os, const TimePoint& time_point) {
  os << ToSecondsSinceEpoch<double>(time_point) << "s";
  return os;
}

std::ostream& operator<<(std::ostream& os, const Duration& duration) {
  os << ToSeconds<double>(duration) << "s";
  return os;
}
