#include "common.hpp"
#include <cerrno>
#include <cstring>
#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
shmid_ds buf;

int main() {
  key_t k = getKey();
  int shmId = shmget(k, SHM_SIZE, IPC_CREAT);
  if (-1 == shmId) {
    std::cerr << errno << ":" << strerror(errno) << std::endl;
    exit(3);
  }
  std::cout << "Key"
            << ":" << dec2hex(k) << std::endl;
  std::cout << "shmId"
            << ":" << dec2hex(shmId) << std::endl;
  delShm(shmId);

  return 0;
}
