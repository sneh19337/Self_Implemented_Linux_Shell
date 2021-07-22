#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
//reading the file
        int i;
        char buf[2];
        int counter = 1;
		int  flag=1;
		int  consec=0;

        void readFile(int fd, int n, int b)
        {
            if ((i = read(fd, buf, 1)) > 0) {
                do {
                    switch (b) {
                        case 1:
                            if (flag == 1 && buf[0] != '\n') {
                                printf("%6d  ", counter);
                                counter++;
                                flag = 0;
                            }
                            switch (buf[0]) {
                                case '\n':
                                    flag = 1;
                                    break;
                            }
                            break;
                        default:
                            switch (n) {
                                case 1:
                                    switch (flag) {
                                        case 1:
                                            printf("%6d  ", counter);
                                            counter++;
                                            flag = 0;
                                            break;
                                    }
                                    switch (buf[0]) {
                                        case '\n':
                                            flag = 1;
                                            break;
                                    }
                                    break;
                            }
                            break;
                    }
                    printf("%c", buf[0]);
                } while ((i = read(fd, buf, 1)) > 0);
            }
        }

        int main(int argc, char *argv[])
        {

            char buffer[1000], filePath[1000];
            int n=0;
			int  b=0;
			int  fileStart=-1;
            {
                int i=1;
                while (i<argc) {
                    if(argv[i][0]=='-'){
                        int j=1;
                        if (argv[i][j] != '\0') {
                            do {
                                if (argv[i][j] == 'n') {
                                    n = 1;
                                } else {
                                    if (argv[i][j] == 'b') {
                                        b = 1;
                                    }
                                }
                                j++;
                            } while (argv[i][j] != '\0');
                        }
                    }
                    else{
                        fileStart = i;
                        break;
                    }
                    i++;
                }
            }
            switch (fileStart) {
                case -1:
                    readFile(0, n, b);
                    return 0;
                default:
                {
                    int i = fileStart;
                    while (argv[i] != NULL) {
                        int fd = open(argv[i], O_RDONLY, 0777);
                        if (fd > 0) {
                            close(fd);
                        } else {
                            printf("Could not open %s\n", argv[i]);
                            return -1;
                        }
                        i++;
                    }
                }
                {
                    int i = fileStart;
                    if (argv[i] != NULL) {
                        do {
                            int fd = open(argv[i], O_RDONLY, 0777);
                            readFile(fd, n, b);
                            close(fd);
                            i++;
                        } while (argv[i] != NULL);
                    }
                }
                    break;
            }

            return 0;
        } 