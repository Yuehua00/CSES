/*
Time limit: 1.00 s
Memory limit: 512 MB

Given an array of n integers, your task is to find the maximum sum of values in a contiguous, nonempty subarray.

Input
  The first input line has an integer n: the size of the array.
  The second line has n integers x_1,x_2,\dots,x_n: the array values.
Output
  Print one integer: the maximum subarray sum.
Constraints
  1 <= n <= 2 * 10^5
  -10^9 <= x_i <= 10^9

Example
  Input:
    8
    -1 3 -2 5 3 -5 2 2
  Output:
    9
*/
#include <iostream>
#include <cmath>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

int main()
{
    ll n;
    scanf("%lld", &n);
    ll arr[n+5][2];
    ll tmp = -10000000000, ans = tmp;
    for(ll i = 0; i < n; i++){
        scanf("%lld", &arr[i][0]);
    }
    arr[0][1] = arr[0][0];
    tmp = arr[0][0];
    for(ll i = 1; i < n; i++){
        arr[i][1] = max(arr[i][0]+tmp, arr[i][0]);   // 選擇留下 當前數字 或是 從前面開始相加(tmp)再加上當前數字 較大者
        tmp = arr[i][1];
        ans = max(tmp, ans);
    }
    ans = max(tmp, ans);
    printf("%lld\n", ans);

    return 0;
}
