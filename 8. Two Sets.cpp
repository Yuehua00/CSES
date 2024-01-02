/*
Time limit: 1.00 s
Memory limit: 512 MB

Your task is to divide the numbers 1,2,...,n into two sets of equal sum.

Input
  The only input line contains an integer n.
Output
  Print "YES", if the division is possible, and "NO" otherwise.
  After this, if the division is possible, print an example of how to create the sets. 
  First, print the number of elements in the first set followed by the elements themselves in a separate line, and then, print the second set in a similar way.
Constraints
  1 <= n <= 10^6

Example 1
  Input:
    7
  Output:
    YES
    4
    1 2 4 7
    3
    3 5 6
Example 2
  Input:
    6
  Output:
    NO
*/
#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long int ull;

int main()
{
    int n = 0;
    scanf("%d", &n);
    vector<int> ans1, ans2;
    ull sum1 = 0, sum2 = 0;
    for(int i = n; i > 0; i--){
        if(sum1 > sum2){
            sum2 += i;
            ans2.emplace_back(i);
        }else{
            sum1 += i;
            ans1.emplace_back(i);
        }
    }
    if(sum1 != sum2){
        printf("NO\n");
    }else{
        printf("YES\n%d\n", ans1.size());
        for(auto i : ans1){
            printf("%d ", i);
        }
        printf("\n%d\n", ans2.size());
        for(auto i : ans2){
            printf("%d ", i);
        }
    }


    return 0;
}

