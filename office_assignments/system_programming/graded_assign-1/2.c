#define  MAX 10
char buf[MAX];
int main()
{
	int fd, ret;
	fd = open("ex.txt", O_RDONLY);
	ret = read(3, buf, MAX);
	printf("%d, %d, %s", fd, ret, :wq

