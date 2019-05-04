#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <stdio.h>


int main()
{

	struct passwd *var;
	uid_t guid = getuid();
	if ((var = getpwuid(guid)) != NULL)
	{
		printf("Entry found............\n");
		printf("User name = %s\n", var->pw_name);
		printf("User password = %s\n", var->pw_passwd);
		printf("User ID = %d\n", var->pw_uid);
		printf("Group ID = %d\n", var->pw_gid);
		printf("Real name = %s\n", var->pw_gecos);
		printf("Home Directory = %s\n", var->pw_dir);
		printf("Shell program= %s\n", var->pw_shell);
	}
	else
	{
		printf("No entry with UID found\n");
	}
	return 0;
}
