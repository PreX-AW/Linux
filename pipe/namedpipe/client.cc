#include "component.hpp"
#include <assert.h>
#include <cstdio>
#include <cstring>
#include <strings.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
  int wfd = open(pipeName.c_str(), O_WRONLY);
  if (wfd < 0) {
    std::cout << errno << ":" << strerror(errno) << std::endl;
    exit(-1);
  }
  char buffer[NUM] = {0};
  while (true) {
    std::cout << "Input message:>" << std::endl;
    char *msg = fgets(buffer, sizeof(buffer), stdin);
    assert(msg);
    (void)msg;
    buffer[strlen(buffer) - 1] = 0;
    if (0 == strcasecmp(buffer, "quit")) {
      std::cout << "Client quit" << std::endl;
      break;
    }
    ssize_t n = write(wfd, buffer, strlen(buffer));
    assert(n >= 0);
    (void)n;
  }
  close(wfd);
  return 0;
}
