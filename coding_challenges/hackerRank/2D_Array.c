/* Given a 6 * 6 2D Array A :
1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0

We define an hourglass in A to be a subset of values with indices falling in this pattern in A's graphical representation:
a b c
  d
e f g

There are 16 hourglasses in A, and an hourglass sum is the sum of an hourglass' values.

Task
Calculate the hourglass sum for every hourglass in A, then print the maximum hourglass sum.

Note: If you have already solved the Java domain's Java 2D Array challenge, you may wish to skip this challenge.

Input Format :
There are 6 lines of input, where each line contains 6 space-separated integers describing 2D Array A; every value in A will be in the inclusive range-9 of to 9 .

Constraints :

-9 <= A[i][j] <= 9
0 <= i , j <= 5

Output Format :
Print the largest (maximum) hourglass sum found in A.

Sample Input :
1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 2 4 4 0
0 0 0 2 0 0
0 0 1 2 4 0

Sample Output :
19

Explanation :
1 1 1   1 1 0   1 0 0   0 0 0
  1       0       0       0
1 1 1   1 1 0   1 0 0   0 0 0

0 1 0   1 0 0   0 0 0   0 0 0
  1       1       0       0
0 0 2   0 2 4   2 4 4   4 4 0

1 1 1   1 1 0   1 0 0   0 0 0
  0       2       4       4
0 0 0   0 0 2   0 2 0   2 0 0

0 0 2   0 2 4   2 4 4   4 4 0
  0       0       2       0
0 0 1   0 1 2   1 2 4   2 4 0



The hourglass with the maximum sum (19) is:
2 4 4
  2
1 2 4

*/

#include <stdio.h>
#define RANGE	9

int main()
{
    int a[6][6];
    int i, j;
    int k, l;
    int max_sum = -100, sum = 0;
    printf("Enter the matrix elements : \n");
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < 4; i++) {
        for(j =0; j < 4; j++) {
            sum = 0;
            for (k = 0; k < 3; k++) {
                if(k != 1) {
                    for (l = 0; l < 3; l++) {
                            sum += a[i+k][j+l];
                    }
                } else {
                    sum += a[i+1][j+1];
                }
           }
            if (sum > max_sum)
                max_sum = sum;
        }   
    }
    printf("Max sum = %d\n", max_sum);
    return 0;
}
