/*Alexandra Rosario Hernandez
* Y00555400
* 
* This is a basic Linux shell made in C
* Supported commands:
*       cd <dir> - Changes current working directory [UNF]
*       pwd - Prints current working directory       [UNF]
*       dir - Displays contents of current dir       [UNF]
*       environ - lists environment settings         [UNF]
*       quit - quit from program with return 0       [UNF]
*       
*/

#include "myshell.h"

pid_t getppid(void);             //init getpid

int main(int argc, char **argv)
{
    //Initial var declaration:

    char line[MAX_BUFFER];
    char cwdbuffer[MAX_BUFFER];         //Holds CWD
    char * prompt = "==>";          //Command prompt
    char * args[MAX_BUFFER];
    char ** arg;
    io input, output;
    

    //Print shell intro, then prompt.

    printf("SIMPLE SHELL: OS Project\n");
    while(!feof(stdin))
    {
        //default state for IO structures
        input.state = 0;
        output.state = 0;

        //reset structure filename and args contents for loopback
        strcpy(input.filename, "");
        strcpy(output.filename, "");
        for (int i = 0; i < MAX_ARGS; i++)
        {
            args[i] = NULL;
        }

        //prompt setup
        if(getcwd(cwdbuffer, sizeof(cwdbuffer)))
            printf("%s %s", cwdbuffer, prompt);      //print prompt
            
        else
        {
            printf("Error retrieving current working directory %s", prompt);
            
        }
        fflush(stdout);                         //remove remaining items from buffer

        if (fgets(line, MAX_BUFFER, stdin))
            {
                arg = args;
                *arg++ = strtok(line, DELIMS);                  //tokenize input
                while ((*arg++ = strtok(NULL, DELIMS)));        //last entry is null
                processCmd(args, cwdbuffer, &input, &output);   //command-processing function is called to parse & exec commands
            }
    }
    return 0;
}