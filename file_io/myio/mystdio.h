#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define BUF_LEN 1024
// define buffer flush mode
#define BUFF_NON 0x1
#define BUFF_LINE 0x2
#define BUFF_ALL 0x4

// define MY_FILE structure
typedef struct MY_FILE {
    int fd;
    int flags;
    char stream_buff[BUF_LEN];
    int current_position;
} MY_FILE;

MY_FILE* my_fopen(const char* pathname, const char* mode);
size_t my_fwrite(const void* ptr, size_t size, size_t num, MY_FILE* stream);
int my_fclose(MY_FILE* stream);
int my_fflush(MY_FILE* stream);

// #define FLAG_READ 0x1
// #define FLAG_WRITE 0x2
// #define FLAG_APPEND 0x4
// typedef struct MY_FILE {
//     int fd;
//     char* buffer[NUM];
//     int flag;
//     int count;
//
// } MY_FILE;
//
// MY_FILE* my_fopen(const char* filepath, const char* flag);
// int my_fclose(MY_FILE* stream);
// size_t my_fwrite(const void* buffer, size_t size, size_t num, MY_FILE* stream);
