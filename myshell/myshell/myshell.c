#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
// Miroo define
#define PROPT "uCloud@uCloud::"
#define COMMAND_LENGTH 1024
#define SUB_COMMAND_NUM 64
#define SEP_TOKEN " "
// Function define
int separate_cmd_str(char *command_input, char **sub_Command);
void Debug_sub_command(char **sub_Command);

int main() {
  extern char **environ;
  int return_code = 0;
  char usr_environ_map[SUB_COMMAND_NUM][COMMAND_LENGTH];
  int usr_environ_map_count = 0;
  while (1) {
    printf("%s", PROPT);
    fflush(stdout);
    char command_input[COMMAND_LENGTH] = {0};
    char *sub_Command[SUB_COMMAND_NUM] = {NULL};
    fgets(command_input, sizeof(command_input), stdin);
    command_input[strlen(command_input) - 1] = '\0';
    // fgets will keep the '\n' in input queue
    assert(command_input);
    int sep_result = separate_cmd_str(command_input, sub_Command);
    if (0 == sep_result) {
      // Debug_sub_command(sub_Command);
      // Check build-in command
      // `cd` command
      if (0 == strcmp(sub_Command[0], "cd")) {
        if (sub_Command[1]) {
          // Check cd to home
          if (0 == strcmp(sub_Command[1], "~")) {
            char *home_pwd = getenv("HOME");
            printf("%s\n", home_pwd);
            chdir(home_pwd);
            continue;
          }
          // change dir to normal path
          chdir(sub_Command[1]);
          continue;
        }
      }
      // `echo` command
      if (0 == strcmp(sub_Command[0], "echo")) {
        if ('$' == *(sub_Command[1])) {
          // echo environment varible
          if ('?' == *(sub_Command[1] + 1)) {
            printf("%d\n", return_code);
            continue;
          }
          char *environment_varible = getenv(sub_Command[1] + 1);
          printf("%s=%s\n", sub_Command[1] + 1, environment_varible);
          continue;
        }
      }
      // `export` command
      if (0 == strcmp(sub_Command[0], "export")) {
        if (NULL != sub_Command[1]) {
          strcpy(usr_environ_map[usr_environ_map_count], sub_Command[1]);
          putenv(usr_environ_map[usr_environ_map_count++]);
        }
        continue;
      }

      // Fork process
      pid_t pid = fork();
      if (0 == pid) {
        // child_process
        execvp(sub_Command[0], sub_Command);
      } else {
        // parent_process
        pid_t wstatus = 0;
        waitpid(-1, &wstatus, 0);
        return_code = WIFEXITED(wstatus);
      }
    }
  }
  return 0;
}

// Function Declearationi
int separate_cmd_str(char *command_input, char **sub_Command) {
  int count = 0;
  sub_Command[count] = strtok(command_input, SEP_TOKEN);
  if (NULL == sub_Command[count]) {
    perror("Separate sting failed.");
    return -1;
  }

  while (sub_Command[count]) {
    count++;
    sub_Command[count] = strtok(NULL, SEP_TOKEN);
  }
  // use system color theme
  if (0 == strcmp(sub_Command[0], "ls")) {
    sub_Command[count++] = "--color=auto";
    sub_Command[count] = NULL;
  }
  return 0;
}

void Debug_sub_command(char **sub_Command) {
  int count = 0;
  while (sub_Command[count]) {
    printf("%d:%s\n", count, sub_Command[count]);
    count++;
  }
}
