#include"mystdio.h"
#include <fcntl.h>
#include <sys/stat.h>




MY_FILE*my_fopen(const char*filepath,const char*flag)
{
  assert(filepath);
  int flags=0;

  umask(0);
  mode_t modecode=0666;
  if(0==strcmp(flag,"r"))flags|=O_RDONLY;
  if(0==strcmp(flag,"w"))flags|=(O_WRONLY|O_CREAT|O_TRUNC);
  if(0==strcmp(flag,"a"))flags|=O_APPEND;
  int fd=open(filepath, modecode);
if(fd<0)
{
  return NULL;

}
 MY_FILE* fp=(MY_FILE*)malloc(sizeof(MY_FILE*)); 
 if(NULL==fp)return NULL;
 fp->fd=fd;
 fp->flag=flags;
 fp->count=0;
 return fp;

}
size_t my_fwrite(const void*buffer,size_t size,size_t num,MY_FILE*stream)
{
  assert(buffer);
  size_t usr_size=size*num;
  size_t write_size=strlen((char*)stream->buffer)-stream->count;
  if(usr_size>write_size)
  {
      //my_fflush before
      
  }
  else
  {
      //write dirctly
  }
}
int my_fclose(MY_FILE*stream)
{
  assert(stream);
  if(strlen((char*)stream->buffer)>0)my_fflush(stream);
  stream->count=0;
  free(stream);
  stream=NULL;




}
