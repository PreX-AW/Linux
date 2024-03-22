#include "mystdio.h"

int main()
{
    MY_FILE* fp = my_fopen("log.txt", "w");
    char msg[2000];
    int index = 0;
    char num = '0';
    while (index < 1998) {
        msg[index] = num;
        index++;
        num++;
        if (num > '9')
            num = '0';
    }
    msg[1999] = '\0';
    my_fwrite(msg, sizeof(char), strlen(msg), fp);
    my_fclose(fp);
    return 0;
}
