  #include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
// this program implements make directory command
#define size 1000
        void upperDir(char p[]){
            int i=0;
            if (p[i] != '\0') {
                do {
                    i++;
                } while (p[i] != '\0');
            }
            int j=i-1;
            if (j >= 0) {
                do {
                    if (p[j] == '/' && j != i - 1) {
                        p[j + 1] = '\0';
                        break;
                    }
                    j--;
                } while (j >= 0);
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
        int parseModes(char mstring[])
        {
            int q = 0;
            int i=0;
            if(strlen(mstring)!=3){ return -1; }
            i=0;
            if (i < 3) {
                do {
                    q = q << 3;
                    int val = (int) (mstring[i] - '0');
                    switch (mstring[i]) {
                        case '\0':
						//if invalid
                            return -1; 
                              default:
                            if (val < 0 || val >= 8) {
							// if not octal
                                return -1; 
                            } else {
                                int j = 0;
                                if ((1 << j) <= 4) {
                                    do {
                                        int flagBit = (1 << j);
                                        q = (q) | (flagBit & val);                                       
                                        j++;
                                    } while ((1 << j) <= 4);
                                }
                            }
                            break;
                    }
                    i++;
                } while (i < 3);
            }
            return q;
        }

        int recursiveMkdir(char path[], int mode)
        {
		int l=0;
            if(strcmp(path,"/")==0){
                return -1;
            }
            int k = mkdir(path,mode);
            if(k<l){
                char path2[1000];
                strcpy(path2,path);
                upperDir(path2);
                k = recursiveMkdir(path2,mode);
            }
            else{
                return 0;
            }
            return mkdir(path, mode);
        }
// main starts 
        int main(int argc, char *argv[]){
            char path[size]="";
            int parentFlag = 0;
            int  modeF = 0;
			char w='m';
			int p=1;
            int  modeArgs = 0777;
            int fileStart=-1;
            {
                int i=1;
                if (i < argc) {
                    do {
                        int j = 1;
                        if (argv[i][0] == '-') {
                            if (argv[i][j] != '\0') {
                                do {
                                    if (argv[i][j] == w) {
                                        modeF = 1;
                                    } else {
                                        if (argv[i][j] == 'p') {
                                            parentFlag = 1;
                                        }
                                    }
                                    j++;
                                } while (argv[i][j] != '\0');
                            }
                        } else {
						//mode begins
                            if (modeF == p) {
                                modeF = 0;
								int d=-1;
                                int givenMode = parseModes(argv[i]);
                                if (givenMode == d) {
                                    modeArgs = 0777;
                                    printf("Not a valid mode !\n");
                                    return -1;
                                } else {
                                    modeArgs = givenMode;
                                }
                            } else {
                                fileStart = i;
                                break;
                            }
                        }
                        i++;
                    } while (i < argc);
                }
            }
            int i=fileStart;
            if (i < argc) {
                do {
                    strcpy(path, argv[i]);
                    int ret;
                    switch (parentFlag) {
                        case 1:
                            ret = recursiveMkdir(path, modeArgs);
                            break;
                        default:
                            ret = mkdir(path, modeArgs);
                            break;
                    }

                    if (ret < 0) {
                        printf("mkdir: directory not created %s !\n", path);
                    }
                    i++;
                } while (i < argc);
            }
            return 0;
        }


