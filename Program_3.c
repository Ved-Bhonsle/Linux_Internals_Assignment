#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>

int main()
{
	struct stat st,st1;
	int fd;

	stat("linuxabc.txt",&st);
	printf("File size: %lu\n",st.st_size);
	printf("File inode: %lu\n",st.st_ino);

	fd=open("file.txt",O_RDONLY);
	fstat(fd,&st1);

	printf("File size: %lu\n",st1.st_size);
	printf("File inode: %lu\n",st1.st_ino);
	return 0;

}
