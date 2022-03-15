#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd1,fd2,len;
	char r_buff[50],m_buff[50];
	char w_buff[50] = "Linux Internals part 1.";

	fd1 = open("file1.txt",O_CREAT | O_RDWR, 777);

	len = write(fd1, w_buff, 50);

	lseek(fd1, 0, SEEK_SET);
	read(fd1, m_buff, len);

	fd2 = open("file2.txt",O_CREAT | O_RDWR,777);
	write(fd2, m_buff, 50);

	lseek(fd2, 0, SEEK_SET);
	read(fd2, r_buff, len);

	printf("Data: %s\n",r_buff);

	close(fd1);
	close(fd2);

	return 0;
}
