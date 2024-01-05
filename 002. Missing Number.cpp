/*
Time limit: 1.00 s
Memory limit: 512 MB

You are given all numbers between 1,2,\ldots,n except one. Your task is to find the missing number.

Input
  The first input line contains an integer n.
  The second line contains n-1 numbers. Each number is distinct and between 1 and n (inclusive).
Output
  Print the missing number.
Constraints
  2 <= n <= 2 * 10^5

Example
  Input:
    5
    2 3 1 5
  
  Output:
    4
*/

#include <iostream>

using namespace std;

typedef unsigned long long int ull;

int main()
{
    ull n = 0, m = 0;
    scanf("%lld", &n);
    ull total = n, tmp = 0;

    for(ull i = 0; i < n-1; i++){
        scanf("%lld", &m);
        total += i+1;
        tmp += m;
    }
    printf("%lld\n", total - tmp);


    return 0;
}
