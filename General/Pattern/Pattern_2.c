// C++ code to demonstrate  printing pattern of numbers
#include <stdio.h> 
// Function to demonstrate printing pattern
void numpat(int n)
{
    // initializing starting number
    int i, j, num = 1;
 
    // outer loop to handle number of rows
    //  n in this case
    for (i=0; i<n; i++)
    {
        // re assigning num
        num = 1;
 
        //  inner loop to handle number of columns
        //  values changing acc. to outer loop
        for (j=0; j<=i; j++ )
        {
            // printing number
            //cout << num << " ";
		printf("%d ",num);
 
            // incrementing number at each column
            num = num + 1;
        }
 
        // ending line after each row
        //cout << endl;
	printf("\n");
	
    }
}
 
// Driver Function
int main()
{
    int n = 6;
    numpat(n);
    return 0;
}
