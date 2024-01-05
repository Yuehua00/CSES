/*
Time limit: 1.00 s
Memory limit: 512 MB

A number spiral is an infinite grid whose upper-left square has number 1. Here are the first five layers of the spiral:
  https://cses.fi/problemset/task/1071/
Your task is to find out the number in row y and column x.

Input
  The first input line contains an integer t: the number of tests.
  After this, there are t lines, each containing integers y and x.
Output
  For each test, print the number in row y and column x.
Constraints
  1 <= t <= 10^5
  1 <= y,x <= 10^9

Example
  Input:
    3
    2 3
    1 1
    4 2
  Output:
    8
    1
    15
*/
#include <iostream>

using namespace std;

typedef unsigned long long int ull;

int main()
{
    ull n = 0, a, b, ans = 0;

    scanf("%lld", &n);
    while(n--){
        scanf("%lld%lld", &a, &b);
        if(a > b){
            if(a % 2 == 0){
                ans = a*a;
                ans -= b-1;
            }
            else{
                ans = (a-1)*(a-1);
                ans += b;
            }
        }else{
            if(b % 2 == 0){
                ans = (b-1)*(b-1);
                ans += a;
            }else{
                ans = b*b;
                ans -= a-1;
            }

        }
        printf("%lld\n", ans);
    }

    return 0;
}

