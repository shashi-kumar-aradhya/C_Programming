#include <stdio.h>
#include <stdlib.h>
void updateEnv (char * str)

{
    char *tmp;
    /* getenv() returns a pointer to the value in the environment or NULL if there is no match */
    tmp = getenv ("MYENV");
    if (tmp!=NULL)
       strcpy(str,tmp);
}

void updateEnvSafe (char * str, size_t strSize)
/*@requires maxSet(str) >= (strSize -1)@*/
{
    char *tmp;
    tmp = getenv ("MYENV");
    if (tmp!=NULL)
    {
       strncpy(str,tmp,strSize-1);
       str[strSize-1] = '\0';
    }
}

