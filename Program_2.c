#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd,len;
	char write_buf[50] = "Linux Internals part 1";
	char read_buf[50];

	fd = open("linuxabc.txt", O_CREAT| O_RDWR , 777);
	len = write(fd, write_buf, 50);
	printf("Return value from write option=%d\n",len);

	lseek(fd,0,SEEK_SET);
	read(fd,read_buf,len);
	printf("Using SEEK_SET : Data from read option =%s\n",read_buf);

	lseek(fd,0,SEEK_END);
	read(fd,read_buf,len);
	printf("Using SEEK_END : Data from read option =%s\n",read_buf);

	lseek(fd,-5,SEEK_CUR);
	read(fd,read_buf,len);
	printf("Using SEEK_CUR : data from read option =%s",read_buf);
	close(fd);

	return 0;
}
