#include "common.hpp"
#include <ostream>
shmid_ds buf;
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
  shmServer server;
  char *start = server.serverAddr();
  int cnt = 0;
  while (cnt < 20) {
    std::cout << "client->server:#" << start << std::endl;
    cnt++;
    fflush(stdout);
    sleep(1);
  }
  std::cout << start << std::endl;

  return 0;
}
