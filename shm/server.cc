#include "common.hpp"
#include <cstring>
#include <sys/ipc.h>
#include <sys/types.h>
int main() {
  umask(0);

  key_t k = getKey();

  int shmId = shmget(k, SHM_SIZE, IPC_CREAT | IPC_EXCL | 0666);
  if (shmId < 0) {
    std::cerr << errno << ":" << strerror(errno) << std::endl;
    exit(2);
  }
  std::cout << "Key"
            << ":" << dec2hex(k) << std::endl;
  std::cout << "shmId"
            << ":" << dec2hex(shmId) << std::endl;

  sleep(10);
  delShm(shmId);
  return 0;
}
