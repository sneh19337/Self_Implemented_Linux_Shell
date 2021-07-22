#include <stdio.h>
#include <string.h>
#include <fcntl.h>           
#include <unistd.h>
// this program is for remove directory          
		int main(int argc, char *argv[]){
            char path[1000]="";
            int interactive = 0;
            int directories = 0;
            int  fileListStart=-1;
            {
                int i=1;
				char r='i';
                if (i < argc) {
                    do {
                        if (argv[i][0] == '-') {
                            int j = 1;
                            if (argv[i][j] != '\0') {
                                do {
                                    if (argv[i][j] == r) {
                                        interactive = 1;
                                    } else {
                                        if (argv[i][j] == 'd') {
                                            directories = 1;
                                        }
                                    }
                                    j=j+1;
                                } while (argv[i][j] != '\0');
                            }
                        } else {
                            fileListStart = i;
                            break;
                        }
                        i++;
                    } while (i < argc);
                }
            }
            switch (fileListStart) {
                case -1:
				//case invalid
                    write(1, "rm: missing operand\n", 20);
                    return 0;
            }
            {
                int i=fileListStart;
                if (i < argc) {
                    do {
                        strcpy(path, argv[i]);
                        char result[ 100];
                        int res = 1;
                        switch (interactive) {
                            case 1:
                                printf("Choose your opinion to remove %s ? (y / n)\n", path);
                                int i = scanf("%s", result);
                                switch (result[0]) {
                                    case 'n':
                                        res = 0;
                                        break;
                                }
                                break;
                        }

                        switch (res) {
                            case 1:
                                res = unlink(path);
                                if (res < 0)
                                    if (directories == 1) {
                                        res = unlinkat(AT_FDCWD, path, AT_REMOVEDIR);
                                    }
                                break;
                        }
                        if (res < 0) {
                            printf("Error Occurred while removing attempt %s\n", path);
                            return res;
                        }
                        i++;
                    } while (i < argc);
                }
            }

            return 0;
        }