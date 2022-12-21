#include "String.hpp"

size_t strlen(const char *str) {
  size_t i{};
  while (*str != 0) {
    i++;
    str += 1;
  }
  return i;
}
