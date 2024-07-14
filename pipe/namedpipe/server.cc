#include "component.hpp"
#include <sys/stat.h>
int main() {
  umask(0);
  int n = mkfifo(pipeName.c_str(), namedPipeMode);
  if (0 == n) {

  } else {
  }
  return 0;
}
