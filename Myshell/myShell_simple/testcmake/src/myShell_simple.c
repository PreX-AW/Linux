//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<unistd.h>
//#include <assert.h>
//#define COMMAND_STR_LENGTH 1024
//#define SUB_COMMAND_NUM 64
//#define SEPARATE_TOKEN " "
//
#include "../include/myShell_simple.h"

int main()
{
	while(1)
	{
		printf("huwei@mymachine:* ");
		fflush(stdout);
		char command_Str[COMMAND_STR_LENGTH]={0};
		char*sub_Command[SUB_COMMAND_NUM]={NULL};
		fgets(command_Str, sizeof(command_Str), stdin);
		command_Str[strlen(command_Str)-1]='\0';
		separate_Command(command_Str,sub_Command);
		//printf_Sub_command(sub_Command);
		execvp(sub_Command[0], sub_Command);


	}

	return 0;
}
