#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<assert.h>
#include<string.h>
#define NUM 1024
#define FLAG_READ   0x1
#define FLAG_WRITE  0x2
#define FLAG_APPEND 0x4



typedef struct MY_FILE
{
  int fd;
  char*buffer[NUM];
  int flag;
  int count;

}MY_FILE;


MY_FILE*my_fopen(const char*filepath,const char*flag);
int my_fclose(MY_FILE*stream);
size_t my_fwrite(const void *buffer,size_t size,size_t num,MY_FILE*stream);
int my_fflush(MY_FILE*stream);
