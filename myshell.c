#include "myshell.h"

pid_t getpid(void);             //init getpid

int main(int argc, char **argv)
{
    //Initial var declaration:

    char line[MAX_BUFFER];
    char cwdbuffer[MAX_BUFFER];         //Holds CWD
    char * prompt = ">>>";          //Command prompt
    char ** args;

    //Print shell intro, then prompt.

    printf("SIMPLE SHELL: OS Project");
    while(!feof(stdin))
    {
        if(getcwd(cwdbuffer, sizeof(cwdbuffer)))
        {
            printf(cwdbuffer, prompt);
        }
        
    }
}