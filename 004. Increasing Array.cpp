/*
Time limit: 1.00 s
Memory limit: 512 MB

You are given an array of n integers. You want to modify the array so that it is increasing, i.e., every element is at least as large as the previous element.
On each move, you may increase the value of any element by one. What is the minimum number of moves required?
讓每一個都不小於前一個

Input
  The first input line contains an integer n: the size of the array.
  Then, the second line contains n integers x_1,x_2,\ldots,x_n: the contents of the array.
Output
  Print the minimum number of moves.
Constraints
  1 <= n <= 2 * 10^5
  1 <= x_i <= 10^9

Example
  Input:
    5
    3 2 5 1 7
  Output:
    5
*/
#include <iostream>

using namespace std;

typedef unsigned long long int ull;

int main()
{

    int n = 0;
    scanf("%d", &n);
    int arr[n+5];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    ull cnt = 0;
    for(int i = 1; i < n; i++){
        if(arr[i] < arr[i-1]){
            cnt += arr[i-1] - arr[i];
            arr[i] = arr[i-1];
        }
    }
    printf("%lld", cnt);

    return 0;
}
