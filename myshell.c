/*Alexandra Rosario Hernandez
* Y00555400
* 
* This is a basic Linux shell made in C
* Supported commands:
*       cd <dir> - Changes current working directory [UNF]
*       pwd - Prints current working directory       [UNF]
*       dir - Displays contents of current dir       [UNF]
*       environ - lists environment settings         [UNF]
*       
*/

#include "myshell.h"

//pid_t getpid(void);             //init getpid

int main(int argc, char **argv)
{
    //Initial var declaration:

    char line[MAX_BUFFER];
    char cwdbuffer[MAX_BUFFER];         //Holds CWD
    char * prompt = "==>";          //Command prompt
    char * args[MAX_BUFFER];
    char ** arg;
    

    //Print shell intro, then prompt.

    printf("SIMPLE SHELL: OS Project\n");
    while(!feof(stdin))
    {
        if(getcwd(cwdbuffer, sizeof(cwdbuffer)))
        {
            printf("%s %s", cwdbuffer, prompt);      //print prompt
            fflush(stdout);                 //remove remaining items from buffer
            if (fgets(line, MAX_BUFFER, stdin))
            {
                arg = args;
                *arg++ = strtok(line, DELIMS);      //tokenize input
                while ((*arg++ = strtok(NULL, DELIMS)));
            }
        }
        else
        {
            printf("Error retrieving current working directory");
        }
        fflush(stdout);

        
    }

    return 0;
}