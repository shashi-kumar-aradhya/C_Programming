#include <stdio.h>
#include <string.h>

#define MAX     100

typedef enum {false, true} bool;


bool str_check(char *p)
{
    int i =0;
    int k =1;
    bool flag =false;
    while(p[i] != '\0') {
        if(p[i] == p[k]) {
            strcpy(&p[i], &p[k+1]);
            k = i+1;
            flag = true;
        }else {
            i++;
            k++;
        }
    }
    return flag;
}   
int main()
{
    char buf[MAX];
    bool flag = true;

    memset(buf, '\0', MAX);
    printf("Enter the string : ");
    fgets(buf, MAX-1, stdin);
    *(buf+strlen(buf)-1) = '\0';    
    while(flag == true) {
        flag = str_check(buf);
    }
    if(*buf)
        printf("%s", buf);
    else 
        printf("Empty String");
}
