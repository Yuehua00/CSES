/*
Time limit: 1.00 s
Memory limit: 512 MB

You have two coin piles containing a and b coins. On each move, you can either remove one coin from the left pile and two coins from the right pile, 
or two coins from the left pile and one coin from the right pile.
Your task is to efficiently find out if you can empty both the piles.

Input
  The first input line has an integer t: the number of tests.
  After this, there are t lines, each of which has two integers a and b: the numbers of coins in the piles.
Output
  For each test, print "YES" if you can empty the piles and "NO" otherwise.
Constraints
  1 <= t <= 10^5
  0 <= a, b <= 10^9

Example
  Input:
    3
    2 1
    2 2
    3 3
  Output:
    YES
    NO
    YES
*/
#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long int ull;

int main()
{
    int n = 0;
    scanf("%d", &n);
    while(n--){
        ull a, b;
        scanf("%lld%lld", &a, &b);
        if(a < b) swap(a, b);
        if((a+b) % 3 != 0 || a > 2*b){    // 因為 a = 2x+y, b = 2y+x => a+b = 3(x+y) || 較小的兩倍大於較大的
            printf("NO\n");
        }else printf("YES\n");
    }

    return 0;
}

