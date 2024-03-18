#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#define LOG1 "log1.txt"
#define LOG2 "log2.txt"
#define LOG3 "log3.txt"
#define LOG4 "log4.txt"
int main()
{
//umask(0);
//close(2);
//const char* buffer="wizard!!!!";
//char read_buffer[100];
// int fd= open(LOG,O_RDONLY);
// printf("fd:%d,errno:%d,strerror:%s\n",fd,errno,strerror(errno));
// ssize_t n=read(fd,read_buffer,sizeof(read_buffer)-1);
// if(n>0)
// {
//   read_buffer[n]='\0';
// }
// printf("%s\n",read_buffer);
//close(fd);
//printf("fd:%d\n",stdout->_fileno);

 int fd1 =open(LOG1,O_RDONLY|O_CREAT);
 printf("fd1:%d\n",fd1);
 int fd2 =open(LOG2,O_RDONLY|O_CREAT);
 printf("fd2:%d\n",fd2);
 int fd3 =open(LOG3,O_RDONLY|O_CREAT);
 printf("fd3:%d\n",fd3);
 close(fd3);
 int fd4 =open(LOG4,O_RDONLY|O_CREAT);
 printf("fd4:%d\n",fd4);

 

  return 0;
}
