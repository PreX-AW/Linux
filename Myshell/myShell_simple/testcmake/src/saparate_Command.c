#include"myShell_simple.h"
void separate_Command(char command_Str[],char*sub_Command[])
{
	assert(command_Str);
	sub_Command[0]=strtok(command_Str, SEPARATE_TOKEN);
	int i=1;
	while(sub_Command[i++]=strtok(NULL, SEPARATE_TOKEN));

}