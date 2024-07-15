#include "component.hpp"
#include <asm-generic/ioctls.h>
#include <assert.h>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <strings.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <system_error>
#include <unistd.h>
struct winsize w;
int main() {
  int wfd = open(pipeName.c_str(), O_WRONLY);
  if (wfd < 0) {
    std::cout << errno << ":" << strerror(errno) << std::endl;
    exit(-1);
  }
  ioctl(0, TIOCGWINSZ, &w);
  char buffer = '\0';
  while (true) {
    if ('\0' == buffer)
      std::cout << "Start Real-Time Communication:>\n"
                << getenv("LOGNAME") << ":";
    system("stty raw");
    buffer = getchar();
    if (0x03 == buffer || 0x04 == buffer) {
      break;
    }
    ssize_t n = write(wfd, &buffer, sizeof(buffer));
    system("stty cooked");
    assert(n >= 0);
    (void)n;
    if ('\r' == buffer) {
      std::cout << std::endl;
      std::cout << "--------------------" << std::endl;
      std::cout << getenv("LOGNAME") << ":";
    }
  }
  close(wfd);
  return 0;
}
