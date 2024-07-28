/*
Time limit: 1.00 s 
Memory limit: 512 MB
There are n apples with known weights. Your task is to divide the apples into two groups so that the difference between the weights of the groups is minimal.
Input
The first input line has an integer n: the number of apples.
The next line has n integers p_1,p_2,\dots,p_n: the weight of each apple.
Output
Print one integer: the minimum difference between the weights of the groups.
Constraints

1 \le n \le 20
1 \le p_i \le 10^9

Example
Input:
5
3 2 7 4 1

Output:
1

Explanation: Group 1 has weights 2, 3 and 4 (total weight 9), and group 2 has weights 1 and 7 (total weight 8).
*/

#include <iostream>
#include <vector>
#include <cmath>
typedef long long int ll;

using namespace std;

vector<ll> apple;
ll n = 0, a = 0;

ll solve(ll now, ll sum1, ll sum2){
    if(now == n) return abs(sum1 - sum2);
    ll way1 = solve(now+1, sum1+apple[now], sum2);
    ll way2 = solve(now+1, sum1, sum2+apple[now]);

    return min(way1, way2);
}

int main()
{
    scanf("%lld", &n);
    for(ll i = 0; i < n; i++){
        scanf("%d", &a);
        apple.emplace_back(a);
    }
    ll ans = solve(0, 0, 0);
    printf("%lld\n", ans);

    return 0;
}
