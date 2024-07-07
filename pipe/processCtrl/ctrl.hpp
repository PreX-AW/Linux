#pragma once
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sched.h>
#include <stdio.h>
#include <string>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <vector>
class EndPoint {
public:
  pid_t _child_pid;
  int _write_fd;
  std::string processName;
  EndPoint(pid_t child_pid, int write_fd)
      : _child_pid(child_pid), _write_fd(write_fd) {
    char processName_Buffer[64];
    snprintf(processName_Buffer, sizeof(processName_Buffer),
             "Process %d [pid:%d] [fd:%d]", cnt++, _child_pid, _write_fd);
    processName = processName_Buffer;
  }

private:
  static int cnt;
};
int EndPoint::cnt = 0;

typedef void (*func_ptr)();
void printLog() {
  std::cout << "Execute printf Log func:process pid is " << getpid()
            << std::endl;
}
void insertMysql() { std::cout << "Execute insert Mysql func" << std::endl; }
void netRequst() { std::cout << "Execute netRequest" << std::endl; }
#define commandLog 0
#define commandMysql 1
#define commandRequest 2
class Task {
public:
  std::vector<func_ptr> funcs;
  Task() {
    funcs.push_back(printLog);
    funcs.push_back(insertMysql);
    funcs.push_back(netRequst);
  }
  void execTask(int command) {
    if (command >= 0 && command < funcs.size())
      funcs[command]();
  }
};
