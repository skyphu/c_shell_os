#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_BUFFER 1024         //Max chars in buffer
#define MAX_ARGS 64          //Max arguments
#define DELIMS " \t\n"          //Delimiters on tokens

#ifndef TRUE
#define TRUE 1                  //Bool
#endif

#ifndef FALSE
#define FALSE 0                 //Bool
#endif

//Structures
struct parsedCmd                //Stores parsed commands
{
    int argc;                   //Count of commands
    char *cmd;                  //Command name
    char *argv[MAX_ARGS]        //Arguments
};

struct inout
{
    int state;
    char filename[MAX_BUFFER]
};

//Vars
extern char **environ;

//Function prototypes
void syserrmsg(char *, char *);
int commandExec();