#include "text_state.h"
#include<string.h>
#include <stdio.h>

Text_State ts;

int main() 
{
	char buffer[100];
	int i;
	ts_init(&ts, 500);
	for(i = 0; i < 4; i++) {
		printf("Enter the string : ");
		fgets(buffer, sizeof(buffer), stdin);
		*(buffer + strlen(buffer)-1) = '\0';
		ts_push_state(&ts, buffer);
	}
	for(i = 0; i < 4; i++) {
		ts_undo(&ts);
	}
	return 0;
}
