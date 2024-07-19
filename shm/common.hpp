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

int createShm(key_t key, size_t shmSize) {
  umask(0);
  int temp = shmget(key, shmSize, IPC_CREAT | IPC_EXCL | 0666);
  assert(-1 != temp), (void)temp;
  std::cout << "shmId:" << temp << std::endl;
  return temp;
}
int getShm(key_t key, size_t shmSize) {
  int temp = shmget(key, shmSize, IPC_CREAT);
  assert(-1 != temp), (void)temp;
  std::cout << "shmId:" << temp << std::endl;
  return temp;
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

char *attachShm(int shmid) {
  void *start = shmat(shmid, nullptr, 0);
  assert((void *)-1 != start), (void)start;
  return ((char *)start);
}

void detachShm(char *shmaddr) {
  int detachResult = shmdt((void *)shmaddr);
  assert(-1 != detachResult), (void)detachResult;
}
class shmClient {
private:
  int shmId;
  char *_start;

public:
  shmClient() {
    key_t k = getKey();
    shmId = getShm(k, SHM_SIZE);
    _start = attachShm(shmId);
    printf("Client attached address %p\n", _start);
  }
  char *clientAddr() const { return _start; }
  ~shmClient() { detachShm(_start); }
};

class shmServer {
private:
  char *_start;
  int shmId;

public:
  shmServer() {
    key_t k = getKey();
    shmId = createShm(k, SHM_SIZE);
    _start = attachShm(shmId);
    printf("Server attached address %p\n", _start);
  }
  char *serverAddr() const { return _start; }
  ~shmServer() {
    detachShm(_start);
    delShm(shmId);
  }
};
#endif
