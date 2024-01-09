/*
Time limit: 1.00 s
Memory limit: 512 MB

There are n sticks with some lengths. Your task is to modify the sticks so that each stick has the same length.
You can either lengthen and shorten each stick. Both operations cost x where x is the difference between the new and original length.
What is the minimum total cost?

Input
  The first input line contains an integer n: the number of sticks.
  Then there are n integers: p_1,p_2,\ldots,p_n: the lengths of the sticks.
Output
  Print one integer: the minimum total cost.
Constraints
  1 <= n <= 2 * 10^5
  1 <= p_i <= 10^9

Example
  Input:
    5
    2 3 1 5 2
  Output:
    5
*/
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

int main(){

    int n = 0;
    scanf("%d", &n);
    int arr[n+5];
    ll mid = 0, midn = 0, ans = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", & arr[i]);
    }
    sort(arr, arr+n);mid = n / 2;
    if(n % 2 == 0){
        midn = (arr[mid] + arr[mid-1]) / 2;
        if(abs(arr[mid] - midn) < abs(arr[mid-1]-midn)){
            midn = arr[mid];
        }else{
            midn = arr[mid-1];
        }
    }else{
        midn = arr[mid];
    }
    for(int i = 0; i < n; i++){
        ans += abs(midn - arr[i]);
    }
    printf("%lld\n", ans);

    return 0;
}
// 找中位數
