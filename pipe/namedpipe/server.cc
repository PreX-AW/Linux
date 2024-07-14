#include "component.hpp"
#include <cerrno>
#include <cstring>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
  umask(0);
  int n = mkfifo(pipeName.c_str(), namedPipeMode);
  if (0 != n) {
    std::cout << errno << strerror(errno) << std::endl;
  }
  int rfd = open(pipeName.c_str(), O_RDONLY);
  if (rfd < 0) {
    std::cout << errno << ":" << strerror(errno) << std::endl;
    exit(-1);
  }
  char buffer[NUM] = {0};
  while (true) {
    buffer[0] = 0;
    ssize_t n = read(rfd, buffer, sizeof(buffer) - 1);
    if (n > 0) {
      buffer[n] = 0;
      std::cout << buffer << std::endl;
    } else if (0 == n) {
      std::cout << "Client quit,server too" << std::endl;
      break;
    } else {
      std::cout << errno << ":" << strerror(errno) << std::endl;
      exit(-1);
    }
  }
  close(rfd);
  unlink(pipeName.c_str());
  return 0;
}
