#include <cerrno>
#include <cstring>
#include <fcntl.h>
#include <iostream>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
const std::string pipeName = "namedPipe";
mode_t namedPipeMode = 0666;

#define NUM 1024
