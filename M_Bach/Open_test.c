#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main() 
{
	 int rp = open("open.txt", O_WRONLY | O_CREAT);
	 int rp_1 = open("open_1.txt", O_CLOEXEC);
	 int rp_2 = open("open_2.txt", O_DIRECTORY);
	 int rp_3 = open("open_3.txt", O_EXCL);
	 int rp_4 = open("open_4.txt", O_NOCTTY);
	 int rp_5 = open("open_5.txt", O_NOFOLLOW);
	 int rp_6 = open("open_6.txt", O_TRUNC);
/*
	 int rp_7 = open("open_7.txt", O_TTY_INIT);
	 int rp_8 = open("open_8.txt", O_WRONLY | O_CREAT);
	 int rp_9 = open("open_9.txt", O_WRONLY | O_CREAT);
	 int rp_10 = open("open_10.txt", O_WRONLY | O_CREAT);
	 int rp_11 = open("open_11.txt", O_WRONLY | O_CREAT);
	 int rp_12 = open("open_12.txt", O_WRONLY | O_CREAT);
	 int rp_13 = open("open_13.txt", O_WRONLY | O_CREAT);
	 int rp_14 = open("open_14.txt", O_WRONLY | O_CREAT);
	 int rp_15 = open("open_15.txt", O_WRONLY | O_CREAT);
	 int rp_16 = open("open_16.txt", O_WRONLY | O_CREAT);
	 int rp_16 = open("open_16.txt", O_WRONLY | O_CREAT);

	printf("Value = %d\n", rp);
*/
	return 0;
}
