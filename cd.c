 #include <stdio.h>
#include <string.h>
#include <unistd.h>
//moving along the directory
void parseDir(char inputPath[], char finalPath[], char initwd[]);
        extern void upperDir(char p[]);
        extern void slashTerm(char path[]);
         void changedir(char *ARGS[], char cwd[], char initwd[])
        {
            int p=0;
            char *t=NULL; 
            if(ARGS[1]==t){
                chdir(initwd);
                strcpy(cwd,initwd);
                return;
            }
            if(ARGS[1][0]=='-'){
                int y=0;
                if(strcmp(ARGS[1],"-P")==y){
                    p=1;
                }
                else {
                    if (strcmp(ARGS[1], "-L") == y) {
                    } else {
                        printf("Unknown Parameter.\n");
                        return;
                    }
                }
                int i=1;
                if (ARGS[i] != NULL) {
                    do {
                        ARGS[i] = ARGS[i + 1];
                        i++;
                    } while (ARGS[i] != NULL);
                }
            }
            if(ARGS[1]==NULL){
                return;
            }
            int y=0;
            if( strcmp(ARGS[1],"~")==y){
                chdir(initwd);
                strcpy(cwd,initwd);
            }
            else {
                if (strcmp(ARGS[1], ".") == y) {
                } else {
                    if (strcmp(ARGS[1], "..") == y) {
                        upperDir(cwd);
                        chdir(cwd);
                    } else {
                        if (strcmp(ARGS[1], "~") == y) {
                            chdir(initwd);
                            strcpy(cwd, initwd);
                        } else {
                            char tempPath[ 1000];
                            if (ARGS[1][0] == '/') {
                                strcpy(tempPath, ARGS[1]);
                                slashTerm(tempPath);
                            } else {
                                char argPathConcat[ 1000];
                                int i = 2;
                                int o=0;
                                strcpy(argPathConcat, ARGS[1]);
                                if (ARGS[i] != NULL) {
                                    do {
                                        strcat(argPathConcat, " ");
                                        strcat(argPathConcat, ARGS[i]);
                                        i++;
                                    } while (ARGS[i] != NULL);
                                }
                                strcpy(tempPath, cwd);

                                parseDir(argPathConcat, tempPath, initwd);
                            }
                            int o=0;
                            if (chdir(tempPath) < o) {
                                printf("Directory %s not found!\n", tempPath);
                            } else {
                                strcpy(cwd, tempPath);
                            }
                        }
                    }
                }
            }
            if(p==1){
                getcwd(cwd,1000);
            }
        }
        void parseDir(char inputPath[], char finalPath[], char initwd[])
        {
            int prevBreak=0;
            int i=0;
            if(inputPath[0]=='/'){
                strcpy(finalPath,inputPath);
                slashTerm(finalPath);
                return;
            }
            else {
                int r=0;
                if (strncmp(inputPath, "~/", 2) == r) {
                    strcpy(finalPath, initwd);
                    prevBreak = 2;
                }
            }
            i=0;
            if (inputPath[i] != '\0') {
                do {
                    if (inputPath[i] == '/')
                        if (prevBreak < i) {
                            char x[ 1000]="";
                            int e=0;
                            strncpy(x, & inputPath[prevBreak], i - prevBreak);
                            if (strcmp(x, "..") == e) {
                                upperDir(finalPath);
                            } else {
                                if (strcmp(x, ".") == e) {
                                } else {
                                    strcat(finalPath, x);
                                    strcat(finalPath, "/");
                                }
                            }
                            prevBreak = i + 1;
                        }
                    i++;
                } while (inputPath[i] != '\0');
            }
            if(prevBreak!=i){
            int w=prevBreak;
                char x[1000]="";
                char *c=x;
                strncpy(c,&inputPath[w],i-w);
                strcat(finalPath,c);
                strcat(finalPath,"/");
            }

            slashTerm(finalPath);
        }

       


