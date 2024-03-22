#include "mystdio.h"
#include <sys/stat.h>

MY_FILE* my_fopen(const char* pathname, const char* mode)
{
    assert(pathname);
    int flag = 0;
    if (0 == strcmp(mode, "r")) {
        flag |= O_RDONLY;
    }
    if (0 == strcmp(mode, "w")) {
        flag |= O_WRONLY | O_CREAT | O_TRUNC;
    }
    if (0 == strcmp(mode, "a")) {
        flag |= O_WRONLY | O_APPEND | O_CREAT;
    } else {
        // other mode
    }
    int fd = 0;
    umask(0);

    if (flag & O_CREAT)
        fd = open(pathname, flag, 0666);
    if (fd < 0)
        return NULL;

    MY_FILE* fp = (MY_FILE*)malloc(sizeof(MY_FILE));
    if (NULL == fp) {
        // For malloc failed
        close(fd);
        return NULL;
    }

    fp->fd = fd;
    fp->flags |= BUFF_ALL;
    memset(fp->stream_buff, '\0', sizeof(fp->stream_buff));
    fp->current_position = 0;
    return fp;
}
size_t my_fwrite(const void* ptr, size_t size, size_t num, MY_FILE* stream)
{
    size_t write_able_size = sizeof(char) * (BUF_LEN - 1 - stream->current_position);
    //(BUfF_LEN-1) to reserve '\0'
    size_t user_write_size = size * num;
    size_t user_buf_pos = 0;
    while (user_write_size > write_able_size) {
        memcpy(stream->stream_buff + stream->current_position * size, ptr + user_buf_pos, write_able_size);
        stream->current_position = strlen(stream->stream_buff);
        my_fflush(stream);
        user_buf_pos += write_able_size;
        stream->current_position = 0;
        // !change set current_positioino befefor refresh wirte_able_size !!!
        write_able_size = sizeof(char) * (BUF_LEN - 1 - stream->current_position);
        user_write_size -= write_able_size;
    }
    memcpy(stream->stream_buff, ptr + user_buf_pos, user_write_size);
    stream->current_position = user_write_size / size;
    stream->stream_buff[stream->current_position] = '\0';
    return user_write_size;
}

int my_fclose(MY_FILE* stream)
{
    if (strlen(stream->stream_buff))
        my_fflush(stream);
    int result = close(stream->fd);
    if (result < 0) {
        perror("Close failed!");
        exit(-1);
    }
    free(stream);
    stream = NULL;
    return 0;
}

int my_fflush(MY_FILE* stream)
{
    write(stream->fd, stream->stream_buff, stream->current_position);
    return 0;
}

// MY_FILE* my_fopen(const char* filepath, const char* flag)
//{
//     assert(filepath);
//     int flags = 0;
///
//    umask(0);
//    mode_t modecode = 0666;
//    if (0 == strcmp(flag, "r"))
//        flags |= O_RDONLY;
//    if (0 == strcmp(flag, "w"))
//        flags |= (O_WRONLY | O_CREAT | O_TRUNC);
//    if (0 == strcmp(flag, "a"))
//        flags |= O_APPEND;
//    int fd = open(filepath, modecode);
//    if (fd < 0) {
//        return NULL;
//    }
//    MY_FILE* fp = (MY_FILE*)malloc(sizeof(MY_FILE));
//    if (NULL == fp)
//        return NULL;
//    fp->fd = fd;
//    fp->flag = flags;
//    fp->count = 0;
//    return fp;
//}
// size_t my_fwrite(const void* buffer, size_t size, size_t num, MY_FILE* stream)
//{
//    assert(buffer);
//    size_t usr_size = size * num;
//    size_t write_size = strlen((char*)stream->buffer) - stream->count;
//    if (usr_size > write_size) {
//        // my_fflush before
//        memcpy(stream->buffer, buffer, use_size - write_size);
//        stream->count = my_fflush(stream);
//        memcpy(stream->buffer, buffer +, size_t n)
//
//    } else {
//        // write dirctly
//        memcpy(stream->buffer, buffer, write_size);
//    }
//}
// int my_fclose(MY_FILE* stream)
//{
//    assert(stream);
//    if (strlen((char*)stream->buffer) > 0)
//        my_fflush(stream);
//    stream->count = 0;
//    free(stream);
//    stream = NULL;
//}
