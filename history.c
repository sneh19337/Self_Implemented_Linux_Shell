#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
//program to implement history
        extern char history[1000][1000];
        extern int hsiz;
        int showhistory(int argc, char *argv[]){
            int f=0;
			int deleteOffset = 0;
            int  delFlag=0;
            int  startLoc=-1;
            int offSet=0;
            int clear = 0;
            int y=1;
			 char buffer[1000]="";
            for(int i=1; i<argc; i++)
            {
                if(deleteOffset==y)
                {
                    offSet = atoi(argv[i]);
                    deleteOffset=0;
                    if(offSet!=f){
                        delFlag = 1;
                    }
                    else{
                        return -1;
                    }
                }
                else if(argv[i][0]=='-'){
                    int j=y;
                    if (argv[i][j] != '\0') {
                        do {
                            if (argv[i][j] == 'c') {
                                clear = 1;
                            } else {
                                if (argv[i][j] == 'd') {
                                    deleteOffset = y;
                                }
                            }
                            j++;
                        } while (argv[i][j] != '\0');
                    }
                }
                else{
                    break;
                }
            }
            if(clear==f && delFlag==f)
            {
                int i=1;
                if (i <= hsiz) {
                    do {
                        printf("%6d  %s\n", i, history[i]);
                        i++;
                    } while (i <= hsiz);
                }
            }
            else if(clear==y)
            {
                while(hsiz>f)
                {
                    strcpy(history[hsiz--],"");
                }
            }
            else {
                if (delFlag == y) {
                    if (offSet > hsiz) {
                        printf("Invalid offset !\n");
                        return -1;
                    } else {
                        int i = offSet;
                        if (i <= hsiz) {
                            do {
                                strcpy(history[i], history[i + 1]);
                                i++;
                            } while (i <= hsiz);
                        }
                        strcpy(history[hsiz--], "");
                    }
                }
            }
            return 0;
        }




	
	
	
