#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
// program to implement echo command
        void parseArgs(char expandedStr[])
        {
            char origStr[1000];
            int ctrl=0;
            int j=0;
            int i=0;
            int w=1;
            strcpy(origStr,expandedStr);
            strcpy(expandedStr,"");
            i = 0;
            if (origStr[i] != '\0') {
                do {
                    if (origStr[i] == '\\') {
                        ctrl = 1;
                    } else {
                        if (ctrl == w) {
    //escape characters provided
                            if (origStr[i] == 'b') {
                                expandedStr[j++] = '\b';
                            } else {
                                if (origStr[i] == 'n') {
                                    expandedStr[j++] = '\n';
                                } else {
                                    if (origStr[i] == 't') {
                                        expandedStr[j++] = '\t';
                                    } else {
                                        if (origStr[i] == 'v') {
                                            expandedStr[j++] = '\v';
                                        } else {
                                            if (origStr[i] == 'a') {
                                                expandedStr[j++] = '\a';
                                            } else {
                                                if (origStr[i] == 'r') {
                                                    expandedStr[j++] = '\r';
                                                } else {
                                                    if (origStr[i] == '\\') {
                                                        expandedStr[j++] = '\\';
                                                    } else {
                                                        if (origStr[i] == '0') {
                                                            expandedStr[j++] = '\0';
                                                        } else {
                                                            expandedStr[j++] = '\\';
                                                            expandedStr[j++] = origStr[i];
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            ctrl = 0;
                        } else {
                            expandedStr[j] = origStr[i];
                            j++;
                        }
                    }
                    ++i;
                } while (origStr[i] != '\0');
            }
            expandedStr[j]='\0';
        }

        void echo(int argc, char *argv[]){
//The arguments of the program
            char buffer[1000]="";
            int newL = 0;
            int escape = 0;
            int startLoc=-1;
            int w=1;
            {
                int i=1;
                if (i < argc) {
                    do {
                        if (argv[i][0] == '-') {
                            int j = w;
                            if (argv[i][j] != '\0') {
                                do {
                                    if (argv[i][j] == 'n') {
                                        newL = w;
                                    } else {
                                        if (argv[i][j] == 'e') {
                                            escape = w;
                                        }
                                    }
                                    j++;
                                } while (argv[i][j] != '\0');
                            }
                        } else {
                            startLoc = i;
                            break;
                        }
                        i++;
                    } while (i < argc);
                }
            }

            int i=startLoc;
            if (i < argc && i > 0) {
                do {
                    strcat(buffer, argv[i]);
                    if (i != argc - 1)
                        strcat(buffer, " ");
                    i++;
                } while (i < argc && i > 0);
            }
            switch (escape) {
                case 1:
                    parseArgs(buffer);
                    break;
            }
            printf("%s",buffer);
            if(newL!=1){
                printf("\n");
            }
        }


	
	
