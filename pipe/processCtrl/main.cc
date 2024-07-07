#include "ctrl.hpp"
#include <sys/wait.h>
int g_child_proc_num = 3;
Task task;
void waitProcess(std::vector<EndPoint> &endpoints) {
  while (true) {
    for (int i = 0; i < endpoints.size() - 1; i++) {
      close(endpoints[i]._write_fd);
    }
    for (int i = 0; i < endpoints.size() - 1; i++) {
      waitpid(endpoints[i]._child_pid, nullptr, 0);
    }
  }
}
void waitCommand() {
  while (true) {
    int command = 0;
    int n = read(0, &command, sizeof(int));
    if (n == sizeof(int)) {
      task.execTask(command);
    } else if (0 == n) {
      std::cout << "Parent close pipe input,child exit!" << std::endl;
    } else {
      break;
    }
  }
}

void createProcess(std::vector<EndPoint> *endpoints) {
  for (int i = 0; i < g_child_proc_num; i++) {
    int pipefd[2] = {0};
    int n = pipe(pipefd);
    assert(-1 != n);
    (void)n;
    pid_t fork_result = fork();
    if (0 == fork_result) {
      // child process
      close(pipefd[1]);
      dup2(pipefd[0], 0);
      close(pipefd[0]);
      waitCommand();
      exit(1);
    }
    // parent process
    close(pipefd[0]);
    endpoints->push_back(EndPoint(fork_result, pipefd[1]));
  }
}
int menu() {
  int selectNum;
  std::cout << "0.Log 1.Mysql" << std::endl;
  std::cout << "2.Net 3.Quit " << std::endl;
  std::cin >> selectNum;
  return selectNum;
}
void ctrlProcess(std::vector<EndPoint> &endpoints) {
  int num = 0;
  int cnt = 0;
  while (true) {
    int command = menu();
    if (3 == command)
      break;
    if (command < 0 || command > 3)
      continue;
    int index = cnt++;
    index = index % endpoints.size();
    std::string name = endpoints[index].processName;
    std::cout << "Select child process " << name
              << "pid: " << endpoints[index]._child_pid << std::endl;
    write(endpoints[index]._write_fd, &command, sizeof(command));
    sleep(1);
  }
}
int main() {
  std::vector<EndPoint> endpoints;
  createProcess(&endpoints);
  ctrlProcess(endpoints);
  waitProcess(endpoints);
  return 0;
}
