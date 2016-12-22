#include <stdio.h>
int gcd(int m, int n)
{
	return m % n ? gcd(n, m%n) : n;
}

int main()
{
	int m, n;
	printf("Enter m : ");
	scanf("%d", &m);
	printf("Enter n : ");
	scanf("%d", &n);
	printf("Gcd = %d\n", gcd(m, n));
	return 0;
}

