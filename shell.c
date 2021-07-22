#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define _GNU_SOURCE
#include <stdlib.h>
#include <sys/wait.h>
#include "cd.c"
#include "echo.c"
#include "history.c"
//the shell stimulator begins here
 void printhelp(){
            write(1,"This is a unix stimulator shell\n",35);
            write(1,"Operating Systems 2020 Assignment1\n",25);
            write(1,"5 internal and external commands replicated  \n",20);
            write(1,"It is provided with a doc to see the  tests \n",70);
            
        }
extern int execvpe(const char *file, char *const argv[], char *const envp[]);

        char history[1000][1000];
        int hsiz = 0;
        char cwd[1000],initwd[1000];

        struct alias{
            char oldname[100];
            char newname[100];
        };
void upperDir(char p[])
{
    
    int i=0;
    while(p[i]!='\0'){i++;}
    int j=i-1;
    while(j>=0){
        if(p[j]=='/' && j!=i-1){
            p[j+1]='\0';
            break;
        }
        j--;
    }
}

void slashTerm(char path[])
{
    int k=strlen(path);
    if(path[k-1]!='/'){
        path[k]='/';
        path[k+1]='\0';
    }
}

//function to load history

        void loadHistory(char initwd[])
        {
            hsiz = 0;
            for(int i=0; i<1000; i++)
            {
                strcpy(history[i],"");
            }
            char filePath[1000];
            strcpy(filePath,initwd);
            strcat(filePath,".save_history_shell");
            FILE *fp = fopen (filePath,"r");
            if(fp==NULL){
            }
            else{
                char str[1000];
                if ((fgets(str, 1000, fp)) != NULL) {
                    do {
                        str[strlen(str) - 1] = '\0';
                        if (strcmp(str, "\n") != 0) {
                            strcpy(history[++hsiz], str);}
                    } while ((fgets(str, 1000, fp)) != NULL);}}}

        void saveHistory(int offset,char initwd[])
        {
            if(offset <=0){ offset = 1;}
            char filePath[1000];
            strcpy(filePath,initwd);
            strcat(filePath,".save_history_shell");
            FILE * fp = fopen (filePath,"w"
);
            int i=offset;
            if(i<=hsiz){
           do {
                fprintf (fp, "%s\n",history[i]);
                i++;}
                while(i<=hsiz);
                }
                }
void saveCmd(char cmd[])
        {
        int e=(1000)/2;
            if(hsiz==999){
            
                saveHistory(e, initwd);
                loadHistory(initwd);}
            strcpy(history[++hsiz],cmd);}
			//main begins
        int main(int argc, char *argv[], char * envp[])
        {
            int exitCode=0;
            int  suppress=0;
            write(1,"hello",5);
            readlink("/proc/self/exe", initwd, 1000);
            upperDir(initwd);
            slashTerm(initwd);
{                int i = 0;int u=0;
                if (envp[i] != NULL) {
                    do {
                        if (strncmp(envp[i], "PWD=", 4) == u) {
                            strcpy(cwd, & envp[i][4]);
                            slashTerm(cwd);
                            break;
                        }
                        i++;
                    } while (envp[i] != NULL);}}
struct alias aliases[50] = {
                {"ll", "ls -1a"} };
loadHistory(initwd);
if (1) {
                do {
                    char cmd[ 1000]="";
                    char cmdBackup[1000] = "";
                    char fileLoc[ 1000] =""; 
                    int q=0;   
                    char *ARGS[100]; 
                    printf("\e[33mSNEH_UNIX\e[0m \e[35m(%s)\e[0m  \e[34m>>>\e[0m ", cwd);
                    if (fgets(cmd,1000, stdin) == NULL) {

                        break;
                        continue;
                    }
                    if (strcmp("\n", cmd) == q) {
                        continue;
                    } else {
                        if (strcmp("", cmd) == q) {
                            
                          continue;
                        }
                    }
                    cmd[strlen(cmd) - 1] = '\0';

                    strcpy(cmdBackup, cmd);

                    {
                        int i = 0;
                        while (strcmp(aliases[i].oldname, "") != 0) {
                            if (strcmp(aliases[i].oldname, cmd) == 0) {
                                strcpy(cmd, aliases[i].newname);
                                break;
                            }
                            i++;
                        }
                    }

                    char*tok;
                    int numArgs = 0;
                    tok = strtok(cmd, " ");
                    if (tok != 0) {
                        do {
                            ARGS[numArgs] = tok;
                            numArgs++;
                            tok = strtok(0, " ");
                        } while (tok != 0);
                    }

                    ARGS[numArgs] = NULL;

                    if (strcmp("exit", ARGS[0]) == 0) {
                        int i = 1;
                        if (ARGS[i] != NULL) {
                            do {
                                if (ARGS[i][0] == '-') {
                                    int k = 1;
                                    if (ARGS[i][k] != '\0') {
                                        do {
                                            if (ARGS[i][k] == 's') {
                                                suppress = 1;
                                                break;
                                            }
                                            k++;
                                        } while (ARGS[i][k] != '\0');
                                    }
                                } else {
                                    exitCode = atoi(ARGS[i]);
                                    break;
                                }
                                i++;
                            } while (ARGS[i] != NULL);
                        }
                        saveCmd(cmdBackup);
                        break;
                    } else
                         {
                    int l=0;
                        if (strcmp("cd", ARGS[0]) == l) {
                            changedir(ARGS, cwd, initwd);
                            saveCmd(cmdBackup);
                            continue;
                        } else {
                            if (strcmp("pwd", ARGS[0]) == l) {
                            char z='L';
                            char b='P';
                                int p = 0;    
                                 int i = 1;
                                if (ARGS[i] != NULL) {
                                    do {
                                        if (ARGS[i][0] == '-') {
                                            int k = 1;
                                            while (ARGS[i][k] != '\0') {
                                                if (ARGS[i][k] == z) {
                                                    p = 0;
                                                } else {
                                                    if (ARGS[i][k] == b) {
                                                        p = 1;
                                                    }
                                                }
                                                k++;
                                            }
                                        }
                                        i++;
                                    } while (ARGS[i] != NULL);
                                }
                                char buf[ 1024]="";
                                switch (p) {
                                    case 1:
                                        getcwd(buf, 1000);

                                        break;
                                    default:
                                        strcpy(buf, cwd);
                                        break;
                                }
                                printf("%s\n", buf);
                                saveCmd(cmdBackup);
                                continue;
                            } else {
                            int y=0;
                                if (strcmp("echo", ARGS[0]) == y) {
                                    echo(numArgs, ARGS);
                                    saveCmd(cmdBackup);
                                    continue;
                                } else {
                                    if (strcmp("history", ARGS[0]) == y) {
                                        showhistory(numArgs, ARGS);
                                        saveCmd(cmdBackup);
                                        continue;
                                    } else {
                                        if (strcmp("help", ARGS[0]) == y) {
                                            printhelp();
                                            saveCmd(cmdBackup);
                                            continue;
                                        } else {
                                            if (strcmp("evars", ARGS[0]) == y) {
                                                
                                                     int i;
                                                i = 0;
                                                if (envp[i] != NULL) {
                                                    do {
                                                        printf("\n%s", envp[i]);
                                                        i++;
                                                    } while (envp[i] != NULL);
                                                }
                                                saveCmd(cmdBackup);
                                                continue;
                                            } else {
                                                strcpy(fileLoc, initwd);
                                                strcat(fileLoc, ARGS[0]);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }

                    int pid = fork();
                    switch (pid) {
                        case 0:
                            execve(fileLoc, ARGS, envp);
                            printf("Command Not Accepted|\e[35m%s\e[0m|. Sorry !\n", ARGS[0]);
                            exit(0);
                            break;
                        default:
                            wait(NULL);
                            saveCmd(cmdBackup);
                            break;
                    }
                } while (1);
            }
            switch (suppress) {
                case 0:
                    write(1,"The Shell Ends !!!\n",15);
                    break;
            }
            saveHistory(1,initwd);
            return exitCode;
        }


  
