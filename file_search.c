#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void test(char *name);

int main(int argc, char * argv[])
{
	char cwd[PATH_MAX];
	char buf[PATH_MAX];
	getcwd(cwd, sizeof(cwd));
	while( argc > 1) 
	{
		argc--;
		memset(buf, '\0', sizeof(buf));
		strcpy(buf, cwd);
		strcat(buf, "/");
		strcat(buf, argv[argc]);
		test(buf);
	}
	printf("List is completed\n");
}
void test(char *name)
{
	DIR *d;
	struct dirent *dir;
	d = opendir(name);
	char cwd[PATH_MAX];
	int fd1; 
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			if(DT_REG == dir->d_type && strstr(dir->d_name, ".c"))
		       	{
      				printf("%s/%s\n", name, dir->d_name);
				strcpy(cwd,  name);
				strcat(cwd, "/");
				strcat(cwd, dir->d_name);
				strcat(cwd,".new");
				fd1 = open(cwd, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
				printf("Write : %lu\n", write(fd1, cwd, strlen(cwd)));
				close(fd1);
			}
			else if (DT_DIR == dir->d_type && strcmp(dir->d_name, ".") && strcmp(dir->d_name, ".."))
			{
				strcpy(cwd,  name);
				strcat(cwd,"/");
				strcat(cwd, dir->d_name);
				test(cwd);
			}
		}
		closedir(d);
	}
}
