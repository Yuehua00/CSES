/*
Time limit: 1.00 s
Memory limit: 512 MB

You are given the arrival and leaving times of n customers in a restaurant.
What was the maximum number of customers in the restaurant at any time?

Input
  The first input line has an integer n: the number of customers.
  After this, there are n lines that describe the customers. Each line has two integers a and b: the arrival and leaving times of a customer.
  You may assume that all arrival and leaving times are distinct.
Output
  Print one integer: the maximum number of customers.
Constraints
  1 <= n <= 2 * 10^5
  1 <= a < b <= 10^9

Example
  Input:
    3
    5 8
    2 4
    3 9
  Output:
    2
*/
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

typedef unsigned long long int ull;

int main(){

    set<pair<int, int>> time;
    int n, arrival, leaving;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &arrival, &leaving);
        time.insert(make_pair(arrival, 1));     // 進來+1
        time.insert(make_pair(leaving, -1));    // 出去-1
    }
    int cnt = 0, maxn = 0;
    for(auto it : time){
        cnt += it.second;
        maxn = max(maxn, cnt);
    }
    printf("%d\n", maxn);

    return 0;
}
