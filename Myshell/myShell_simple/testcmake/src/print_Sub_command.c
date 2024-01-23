#include"myShell_simple.h"
void printf_Sub_command(char*sub_Command[])
{
	assert(sub_Command);
	int i=0;
	while(sub_Command[i])printf("%d:%s\n",i,sub_Command[i++]);
}
