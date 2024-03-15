#include<stdio.h>
#include<assert.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
// Miroo define
#define PROPT "uCloud@uCloud::"
#define COMMAND_LENGTH 1024
#define SUB_COMMAND_NUM 64
#define SEP_TOKEN " "



// Function define
int separate_cmd_str(char* command_input,char** sub_Command);
void Debug_sub_command(char** sub_Command);



int main()
{
  while(1)
  {
  printf("%s",PROPT);
  fflush(stdout);
  char command_input[COMMAND_LENGTH]="";
  char* sub_Command[SUB_COMMAND_NUM]={NULL};
  fgets(command_input, sizeof(command_input),stdin);
  command_input[strlen(command_input)-1]='\0';
  //fgets will keep the '\n' in input queue
  assert(command_input);
  int sep_result=separate_cmd_str(command_input, sub_Command);  
  if(0==sep_result)
  {
    // Debug_sub_command(sub_Command);
     pid_t pid=fork();
     if(0==pid)
     {
       //child_process
       execvp(sub_Command[0],sub_Command);
     }
     else
     {
       //parent_process
       pid_t wstatus=0;
       waitpid(-1, &wstatus, 0);
     }
  }

  }
  return 0;
}



//Function Declearationi
int separate_cmd_str(char* command_input,char** sub_Command)
{
  int count=0;
  sub_Command[count] = strtok(command_input,SEP_TOKEN);
  if(NULL==sub_Command[count])
  {
  perror("Separate sting failed.");
  return -1;
  }

  while(sub_Command[count])
  {
    count++;
    sub_Command[count]=strtok(NULL, SEP_TOKEN);
  }
  return 0;
}

void Debug_sub_command(char** sub_Command)
{
  int count=0;
  while(sub_Command[count])
  {
    printf("%d:%s\n",count,sub_Command[count]);
    count++;
  }
}

