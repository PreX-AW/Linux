#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include <assert.h>
#define COMMAND_STR_LENGTH 1024
#define SUB_COMMAND_NUM 64
#define SEPARATE_TOKEN " "
void separate_Command(char command_Str[],char*sub_Command[])
{
	assert(command_Str);
	sub_Command[0]=strtok(command_Str, SEPARATE_TOKEN);
	int i=1;
	while(sub_Command[i++]=strtok(NULL, SEPARATE_TOKEN));

}

void printf_Sub_command(char*sub_Command[])
{
	assert(sub_Command);
	int i=0;
	while(sub_Command[i])printf("%d:%s\n",i,sub_Command[i++]);
}


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
