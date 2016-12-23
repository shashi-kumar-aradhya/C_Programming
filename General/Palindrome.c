#include <stdio.h>

int main()
{
	int ori, rev, dup;
	printf("Enter the number : ");
	scanf("%d", &ori);
	dup = ori;
	while (dup) {
		rev = rev * 10 + dup % 10;
		dup /= 10;
	}
	if (rev == ori) {
		printf("Palindrome\n");
	} else {
		printf("NOt a palindrome\n");
	}
	return 0;
}
