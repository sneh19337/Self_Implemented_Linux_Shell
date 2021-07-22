#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
//main begins here
int main(int argc, char *argv[])
{
char buffer[1000];
char filePath[1000];
int r=0;
int R=0;
char e='-';
char u='r';
int o=1;
for(int i=1; i<argc; i++)
{
if(argv[i][0]==e){
int j=1;
while(argv[i][j]!='\0')
{
if(argv[i][j]==u){
r = 1;
}
else if(argv[i][j]=='R')
{
R = 1;
}
j=j+1;
}
}
else{
strcpy(filePath,argv[i]);
}
}
time_t t = time(NULL);
struct tm *tm = localtime(&t);

if(r==o){
struct stat attrib;
if(stat(filePath, &attrib) < 0){
printf("Invalid Path.\n");
return 0;
}
tm = localtime(&(attrib.st_ctime));
}
if(R==o){
strftime(buffer,1000, "%a, %d %b %G %R:%S %z", tm);
}
else{
strftime(buffer,1000, "%a %b %d %R:%S %Z %Y", tm);
}
printf("%s\n", buffer);
return 0;
}