#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FALSE 0
#define TRUE 1
//This program is to implement list
        int oneLine=0;
        int allFiles=0;
        int quote=0;	
		int file_select(const struct dirent *entry)
        {
            if ((entry -> d_name)[0] == '.') {
                if (allFiles == 0) {
                    return (FALSE);
                } else return (TRUE);
            } else {
                return (TRUE);
            }
        }
 int caseialphasort(const struct dirent **e1, const struct dirent **e2) {
const struct dirent **i=e1;
const char *j=(*e2)->d_name;
const char *a = (*i)->d_name;
const char *b = j;
   return strcasecmp(a, b);        }
 // main begins
 int main(int argc, char *argv[]){
            char path[1000]=".";
            {
			char t='Q';
			char e='a';
                int i=1;
				//checking for i
                if (i < argc) {
                    do {
                        if (argv[i][0] == '-') {
                            int j = 1;
                            if (argv[i][j] != '\0') {
                                do {
                                    if (argv[i][j] == t) {
                                        quote = 1;
                                    } else {
                                        if (argv[i][j] == e) {
                                            allFiles = 1;
                                        } else {
                                            if (argv[i][j] == '1') {
                                                oneLine = 1;
                                            }
                                        }
                                    }
                                    j++;
                                } while (argv[i][j] != '\0');
                            }
                        } else {
                            strcpy(path, argv[i]);
                        }
                        i++;
                    } while (i < argc);
                }
            }

            int n;
			int b=1;
            struct dirent **dp;
            n = scandir(path, &dp, &file_select, caseialphasort);
            if(n<0){
                printf("An error occured !\n");
            }
            else{
                int i=0;
                if (i < n) {
                    do {
                        switch (quote) {
                            case 1:
                                printf("\"");
                                break;
                        }
                        printf("%s", dp[i]->d_name);
                        if (quote == b) {
                            printf("\"");
                        }
                        if (oneLine == 0) {
                            printf("  ");
                        } else {
                            printf("\n");
                        }
                        free(dp[i]);
                        i++;
                    } while (i < n);
                }
                free(dp);
            }
            oneLine==1? :printf("\n");
            if (n < 0) return -1;
            return 0;
        }