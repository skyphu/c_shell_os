#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_BUFFER 1024         //Max chars in buffer
#define MAX_ARGS 64          //Max arguments
#define DELIMS " \t\n"          //Delimiters on tokens

typedef struct io io;
struct io
{
    int state;
    char filename[MAX_BUFFER];      //Array of chars to hold filename.
};

//Vars
extern char **environ;

//Function prototypes
void syserrmsg(char *, char *);
void argExec();
void pressEnter();
void processCmd(char * args[MAX_ARGS], char * cwdbuf, io *input, io *output);