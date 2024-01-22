/*
Time limit: 1.00 s
Memory limit: 512 MB

Consider a game where there are n children (numbered 1,2,\dots,n) in a circle. 
During the game, repeatedly k children are skipped and one child is removed from the circle. 
In which order will the children be removed?

Input
  The only input line has two integers n and k.
Output
  Print n integers: the removal order.
Constraints
  1 <= n <= 2 * 10^5
  0 <= k <= 10^9

Example
  Input:
    7 2
  Output:
    3 6 2 7 5 1 4
*/



/* TLE
#include <iostream>
#include <queue>

using namespace std;

int main(){

    int n = 0, k = 0, tmp = 0;
    scanf("%d%d", &n, &k);
    queue<int> pos;
    for(int i = 1; i <= n; i++){
        pos.push(i);
    }
    tmp = k % pos.size();
    for(int i = 0; i < n; i++){
        tmp = k % pos.size();
        for(int j = 0; j < tmp; j++){
            pos.push(pos.front());
            pos.pop();
        }
        printf("%d ", pos.front());
        pos.pop();
    }
    printf("\n");

    return 0;
}

*/
