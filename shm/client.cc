#include "common.hpp"
shmid_ds buf;

int main() {
  //  key_t k = getKey();
  //  // int shmId = shmget(k, SHM_SIZE, IPC_CREAT);
  //  int shmId = getShm(k, SHM_SIZE);
  //  if (-1 == shmId) {
  //    std::cerr << errno << ":" << strerror(errno) << std::endl;
  //    exit(3);
  //  }
  //  std::cout << "Key"
  //            << ":" << dec2hex(k) << std::endl;
  //  std::cout << "shmId"
  //            << ":" << dec2hex(shmId) << std::endl;
  //  shmctl(shmId, 2, &buf);
  //  std::cout << dec2hex(buf.shm_perm.__key) << std::endl;
  //  std::cout << buf.shm_cpid << " " << getpid() << std::endl;
  //  sleep(10);
  //  delShm(shmId);
  //  std::cout << "Client distory shared memory." << std::endl;

  shmClient client;
  char *start = client.clientAddr();
  char c = 'A';
  while (c < 'Z') {
    start[c - 'A'] = c;
    c++;
    start[c - 'A'] = '\0';
    sleep(1);
  }
  sleep(4);
  return 0;
}
