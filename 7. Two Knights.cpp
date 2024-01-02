/*
Time limit: 1.00 s
Memory limit: 512 MB

Your task is to count for k=1,2,\ldots,n the number of ways two knights can be placed on a k \times k chessboard so that they do not attack each other.

Input
  The only input line contains an integer n.
Output
  Print n integers: the results.
Constraints
  1 <= n <= 10000

Example
  Input:
    8
  Output:
    0
    6
    28
    96
    252
    550
    1056
    1848
*/
#include <iostream>

using namespace std;

typedef unsigned long long int ull;

int main()
{
    int n = 0, a = 1, b = 2;
    ull ans = 1;
    scanf("%d", &n);
    printf("0\n");
    for(int j = 2; j <= n; j++){
        for(int i = j*j; i > j*j-2; i--){
            ans *= i;
        }
        ans /= 2;
        if(j > 2){
            ans -= a*b*4;
            a++;
            b++;
        }
        printf("%lld\n", ans);
        ans = 1;
    }

    return 0;
}
