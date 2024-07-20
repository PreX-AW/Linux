#include "common.hpp"

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

  shmClient<buf> client;
  buf *start = client.clientAddr();
  system("stty raw");
  start->x = 'A';
  int temp = start->cnt;
  while (0x04 != start->x && 0x03 != start->x) {
    std::cin >> start->x;
    start->cnt++;
    if (start->cnt > 100)
      start->cnt = 0;
  }
  system("stty cooked");
  return 0;
}
