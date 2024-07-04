#include <cerrno>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <sys/types.h>
#include <unistd.h>
int main() {
  // create pipe
  int pipefd[2] = {0};
  int n = pipe(pipefd);
  if (n < 0) {
    std::cout << "pipe error:" << errno << ":" << strerror(errno) << std::endl;
    exit(-1);
  }
  std::cout << "pipefd[0]:" << pipefd[0] << std::endl;
  std::cout << "pipefd[1]:" << pipefd[1] << std::endl;
  pid_t fork_result = fork();
  if (0 == fork_result) {
    // child process
    std::string nameStr = "Child_message";
    int cnt = 0;
    char buffer[1024];
    close(pipefd[0]);
    while (true) {
      snprintf(buffer, sizeof(buffer), "%s:%d", nameStr.c_str(), cnt++);
      write(pipefd[1], buffer, strlen(buffer));
      sleep(1);
    }
    close(pipefd[1]);
  }
  // parent process;
  char buffer[1024];
  while (true) {
    close(pipefd[1]);
    n = read(pipefd[0], buffer, sizeof(buffer) - 1);
    buffer[n] = '\0';
    std::cout << buffer << std::endl;
  }
  // use fork to create child process
  // close unnessery fd
  // start process communication
  close(pipefd[0]);
  return 0;
}
