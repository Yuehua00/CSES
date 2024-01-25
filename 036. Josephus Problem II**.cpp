// 來源 : https://www.youtube.com/watch?v=KnsDFCcBJbY

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

#include <iostream>
#include <set>

using namespace std;

//****************************************************************************************此區為因為要用find_by_order************
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//******************************************************************************************************************************

int main(){

    int n = 0, k = 0;
    scanf("%d%d", &n, &k);
    ordered_set<int> pos;
    for(int i = 1; i<= n; i++){
        pos.insert(i);
    }
    int start = 0;
    while(n--){
        start %= pos.size();
        int positionToRemove = (start + k) % pos.size();
        start = positionToRemove;
        auto ans = pos.find_by_order(positionToRemove);
        printf("%d ", *ans);
        pos.erase(ans);
    }
    printf("\n");

    return 0;
}


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
