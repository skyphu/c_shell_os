#include "myshell.h"


//parse & process commands using delims
void processCmd(char * args[MAX_ARGS], char * cwdbuffer, io *input, io *output)
{
    char *cmdbuf[MAX_ARGS];
    FILE * file;
    char buffer[MAX_BUFFER];
    for(int i = 0; i < MAX_ARGS; i++)
        cmdbuf[i] = NULL;

    if(args[0])         //If there are arguments
    {
        io_check(args, input, output);              //Parse args, check for changes to io stream
    }
}
//fflush(stdout);             //Flush line buffer

//cd

//clr

//dir

//environ list all environment strings

//echo

//help

//pause
void pressEnter()
{
    printf("Press [ENTER] to continue");
    char enter = 0;
    while (enter != '\r' && enter != '\n')  //While enter isn't carriage return or newline
        enter = getchar();
}

//quit

