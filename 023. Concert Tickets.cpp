/*
Time limit: 1.00 s
Memory limit: 512 MB

There are n concert tickets available, each with a certain price. Then, m customers arrive, one after another.
Each customer announces the maximum price they are willing to pay for a ticket, and after this, 
they will get a ticket with the nearest possible price such that it does not exceed the maximum price.

Input
  The first input line contains integers n and m: the number of tickets and the number of customers.
  The next line contains n integers h_1,h_2,\ldots,h_n: the price of each ticket.
  The last line contains m integers t_1,t_2,\ldots,t_m: the maximum price for each customer in the order they arrive.
Output
  Print, for each customer, the price that they will pay for their ticket. After this, the ticket cannot be purchased again.
  If a customer cannot get any ticket, print -1.
Constraints
  1 <= n, m <= 2 * 10^5
  1 <= h_i, t_i <= 10^9

Example
  Input:
    5 3
    5 3 7 8 5
    4 8 3
  Output:
    3
    8
    -1
*/
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

typedef unsigned long long int ull;

int main(){

    int n, m, tmp1;
    scanf("%d%d", &n, &m);
    multiset<int> tickit;   // multiset 跟 set 用法差不多，選用 multiset 是因為erase只會刪除一個元素，set的erase會刪所有相同元素
    int customer[m+5];

    for(int i = 0; i < n; i++){
        scanf("%d", &tmp1);
        tickit.insert(tmp1);
    }

    for(int i = 0; i < m; i++){
        scanf("%d", &customer[i]);
    }

    for(int i = 0; i < m; i++){
        auto it = tickit.upper_bound(customer[i]);   // upper_bound 會回傳大於的最小數，如果key大於所有數，則回傳最後(set當中最大數)
        if(it != tickit.begin()){
            it--;
            printf("%d\n", *it);
            tickit.erase(it);
        }else{
            printf("-1\n");
        }
    }
    return 0;
}
// 一開始用雙層for迴圈超時
