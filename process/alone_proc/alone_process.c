#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
  pid_t fork_result = fork();
  int count = 0;
  if (0 < fork_result) {
    // parent_process
    printf("I am parent_process.\n");
    sleep(3);
    printf("Parent_process exited!\n");
  }
  if (0 == fork_result) {
    // child_process
    while (count < 10) {
      printf("I am child_process. Counter: %d\n", count++);
      sleep(1);
    }
    printf("Parent_process exited!\n");
  }
  return 0;
}
