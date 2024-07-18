#ifndef __COMMON__HPP__
#define __COMMON__HPP__
#include <cassert>
#include <cerrno>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define PATHNAME "."
#define PROJECT_ID 17
#define SHM_SIZE 4096

key_t getKey() {
  key_t k = ftok(PATHNAME, PROJECT_ID);
  if (-1 == k) {
    std::cerr << errno << ":" << strerror(errno) << std::endl;
    exit(1);
  }
  return k;
}

std::string dec2hex(int num) {
  char buf[64];
  snprintf(buf, sizeof buf, "0x%x", num);
  return buf;
}

void delShm(int shmid) {
  int n = shmctl(shmid, IPC_RMID, nullptr);
  assert(-1 != n), (void)n;
}

#endif
