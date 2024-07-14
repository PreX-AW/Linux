#include <cerrno>
#include <iostream>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
const std::string pipeName = "namedPipe";
mode_t namedPipeMode = 0666;
