/*
Time limit: 1.00 s
Memory limit: 512 MB

Your task is to calculate the number of trailing zeros in the factorial n!.
For example, 20!=2432902008176640000 and it has 4 trailing zeros.

Input
  The only input line has an integer n.
Output
  Print the number of trailing zeros in n!.
Constraints
  1 <= n <= 10^9

Example
  Input:
    20
  Output:
    4
*/
#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long int ull;

int main()
{
    int n = 0;
    ull ans = 0;
    scanf("%d", &n);
    while(n){
		ans+=n/5;
		n/=5;

	}
    printf("%lld\n", ans);

    return 0;
}
// 將 n 除以 5 的結果加到 ans 中，這是因為每隔 5 個數字會出現一個因子 5，而因子 5 會產生一個尾隨零。
