#include <stdio.h>

void possibleSubsets(char A[], int N)
{
	for(int i = 0;i < (1 << N); ++i)
	{
          for(int j = 0;j < N;++j)
              if(i & (1 << j))
//                  cout << A[j] << ‘ ‘;
                  printf("i =  %d j = %d : %c ", i, j, A[j]);
//          cout << endl;
	    printf("\n");
	}
}

int main()
{

char array[10] = "abcdefg";
possibleSubsets(array, 3);
return 0;
}
