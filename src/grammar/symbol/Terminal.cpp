#include <gram/grammar/symbol/Terminal.h>

using namespace gram::grammar;

Terminal::Terminal(std::string value) : val(value) {
  //
}

std::string Terminal::value() {
  return val;
}

bool Terminal::operator==(const Terminal &terminal) const {
  return val == terminal.val;
}

bool Terminal::operator!=(const Terminal &terminal) const {
  return !operator==(terminal);
}
