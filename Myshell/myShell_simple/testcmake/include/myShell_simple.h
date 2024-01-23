#pragma once
#include<stdio.h>
#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include<assert.h>

void separate_Command(char command_Str[],char*sub_Command[]);
void printf_Sub_command(char*sub_Command[]);

#define COMMAND_STR_LENGTH 1024
#define SUB_COMMAND_NUM 64
#define SEPARATE_TOKEN " "

