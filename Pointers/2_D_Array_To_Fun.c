#include <stdio.h>
#include <string.h>
#define MAX 10
void fun(int temp,int temp1, char value[][MAX],int temp2, int n)
{
	int i = 0, j = n-1;
	printf("Temp = %p\n", &temp);
	printf("Temp 1 = %p\n", &temp1);
	printf("value add = %p\n", &value);
	printf("Temp 2 = %p\n", &temp2);
	printf("n = %p\n\n\n", &n);
	printf("value  val = %p\n", &value[i]);

	for (i = 0; i < n; i++)
	printf("value = %p\n", value[i]);
	char buf[MAX];
	for (i = 0; i < n; i++) {
		printf("[%d] : string = %s\n", i, value[i]);
	}

	i = 0;
	while(i < j) {
		printf("i = %d\tj = %d\n", i, j);
		memset(buf,'\0', MAX);
		strcpy(buf, value[i]);
		memset(value[i], '\0', MAX);
		strcpy(value[i], value[j]);
		memset(value[j], '\0', MAX);
		strcpy(value[j], buf);
		printf("i = [%d] : string = %s\n", i, value[i]);
		printf("j = [%d] : string = %s\n", j, value[j]);
		i++;
		j--;
	}
	
	printf("In func\n");
	for (i = 0; i < n; i++) {
		printf("[%d] : string = %s\n", i, value[i]);
	}

	return ;
}

int main() 
{
	int i = 0;

	char data[3][MAX] = {"shashi","kumar","aradhya"};
	printf("Data add = %p\n", &data);
	for (i = 0; i < 3; i++)
	printf("Data = %p\n", data[i]);
	printf("\n");
	fun(10,10, data, 0, 3);
	printf("In main\n");
	for (i = 0; i < 3; i++)
		printf("[%d] : string = %s\n", i, data[i]);
	return 0;
}

