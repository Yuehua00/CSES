// 參考 : https://www.youtube.com/watch?v=Z98NA0F7C0s
/*
Time limit: 1.00 s
Memory limit: 512 MB

There are n books, and Kotivalo and Justiina are going to read them all. For each book, you know the time it takes to read it.
They both read each book from beginning to end, and they cannot read a book at the same time. What is the minimum total time required?
Input
The first input line has an integer n: the number of books.
The second line has n integers t_1,t_2,\dots,t_n: the time required to read each book.
Output
Print one integer: the minimum total time.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le t_i \le 10^9

Example
Input:
3
2 8 3

Output:
16
*/
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <cmath>
typedef long long int ll;

using namespace std;


vector<ll> book;
ll n = 0, a = 0;

int main()
{
    ll total = 0;
    scanf("%lld", &n);
    for(ll i = 0; i < n; i++){
        scanf("%d", &a);
        book.emplace_back(a);
        total += a;
    }
    sort(book.begin(), book.end());

    printf("%lld\n", max(total, 2*book[n-1]));  // 2倍最長時間和總時間取最大者


    return 0;
}
