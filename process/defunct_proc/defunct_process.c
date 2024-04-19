#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
  pid_t fork_result = fork();
  int count = 0;
  if (fork_result > 0) {
    // parent_process
    sleep(20);
    printf("I am parent_process.\n");
  }
  if (0 == fork_result) {
    // child_process
    while (count < 10) {
      printf("I am child_process, counter:%d\n", count++);
      sleep(1);
    }
  }
  return 0;
}
