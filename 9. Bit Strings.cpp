/*
Time limit: 1.00 s
Memory limit: 512 MB

Your task is to calculate the number of bit strings of length n.
For example, if n=3, the correct answer is 8, because the possible bit strings are 000, 001, 010, 011, 100, 101, 110, and 111

Input
  The only input line has an integer n.
Output
  Print the result modulo 10^9+7.
Constraints
  1 <= n <= 10^6

Example
  Input:
    3
  Output:
    8
*/
#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long int ull;

int main()
{
    int n = 0;
    scanf("%d", &n);
    ull ans = 1;
    ull a = pow(10, 9);
    a += 7;
    ans %= a;
    for(int i = 0; i < n; i++){
        ans *= 2;
        ans %= a;
    }
    printf("%lld\n", ans);

    return 0;
}
