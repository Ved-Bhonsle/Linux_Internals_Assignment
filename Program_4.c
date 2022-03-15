#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
int fd,len;
char r_buf[100];
char buf[100]="All system calls in one program";

creat("all_sys_call.txt",0755);
fd = open("all_sys_call.txt",O_WRONLY);
len = write(fd,buf,50);

lseek(fd,0,SEEK_SET);
read(fd,r_buf,len);
printf("Data from read option : %s\n",r_buf);
close(fd);

fd=open("all_sys_call.txt",O_RDONLY);
read(fd,r_buf,len);
printf("%s\n",r_buf);
close(fd);

return 0;
}
