#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_BUFFER 1024         //Max chars in buffer
#define MAX_ARGS 128           //Max arguments
#define DELIMS " \t\n"          //Delimiters on tokens

#ifndef TRUE
#define TRUE 1                  //Bool
#endif

#ifndef FALSE
#define FALSE 0                 //Bool
#endif

typedef struct io io;
struct io
{
    int state;
    char filename[MAX_BUFFER]
};

