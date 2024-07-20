#include "common.hpp"
#include <cstdio>
#include <ncurses.h>
#include <ostream>
int main() {

  //  key_t k = getKey();
  //
  //  // int shmId = shmget(k, SHM_SIZE, IPC_CREAT | IPC_EXCL | 0666);
  //  int shmId = createShm(k, SHM_SIZE);
  //  if (shmId < 0) {
  //    std::cerr << errno << ":" << strerror(errno) << std::endl;
  //    exit(2);
  //  }
  //  std::cout << "Key"
  //            << ":" << dec2hex(k) << std::endl;
  //  std::cout << "shmId"
  //            << ":" << dec2hex(shmId) << std::endl;
  //
  //  shmctl(shmId, 2, &buf);
  //  std::cout << dec2hex(buf.shm_perm.__key) << std::endl;
  //  std::cout << buf.shm_cpid << " " << getpid() << std::endl;
  //  sleep(10);
  //  delShm(shmId);
  //  std::cout << "Server distory shared memeory." << std::endl;
  shmServer<buf> server;
  buf *start = (buf *)server.serverAddr();
  std::cout << "Get message form client:>" << std::endl;
  int temp = start->cnt;
  while (0x03 != start->x && 0x04 != start->x) {
    if (temp == start->cnt) {
      continue;
    }
    switch (start->x) {
    case '\n':
      printf("\n");
      temp = start->cnt;
      break;
    case 0x08:
      printf("\b");
      fflush(stdout);
      temp = start->cnt;
      break;
    default:
      printf("%c", start->x);
      temp = start->cnt;
      fflush(stdout);
    }
  }

  return 0;
}
