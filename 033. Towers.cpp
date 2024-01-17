/*
Time limit: 1.00 s
Memory limit: 512 MB

You are given n cubes in a certain order, and your task is to build towers using them.
Whenever two cubes are one on top of the other, the upper cube must be smaller than the lower cube.
You must process the cubes in the given order. You can always either place the cube on top of an existing tower, or begin a new tower. What is the minimum possible number of towers?

Input
  The first input line contains an integer n: the number of cubes.
  The next line contains n integers k_1,k_2,\ldots,k_n: the sizes of the cubes.
Output
  Print one integer: the minimum number of towers.
Constraints
  1 <= n <= 2 * 10^5
  1 <= k_i <= 10^9

Example
  Input:
    5
    3 8 2 1 5
  Output:
    2
*/

/*
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

    int n = 0;
    scanf("%d", &n);
    int arr[n+5];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    vector<vector<int>> tower(n);
    int in = 0, now = 0, last = 0, maxn = 0;
    for(int i = 0; i < n; i++){
        if((arr[i] == arr[i-1] && i-1 >= 0) || arr[i] >= maxn){
            tower[now].emplace_back(arr[i]);
            now++;
            maxn = max(maxn, arr[i]);
            if(arr[i+1] < arr[i]) last = 0;
            in = 0;
            continue;
        }
        for(int j = last; j < now; j++){
            if(arr[i] < tower[j][tower[j].size()-1]){
                //cout << tower[j+1].size() << endl;
                if(tower[j][tower[j].size()-1] == maxn && now >= j+1 && tower[j+1].size() > 0) maxn = max(arr[i], tower[j+1][(int)tower[j+1].size()-1]);
                else if(tower[j][tower[j].size()-1] == maxn) maxn = arr[i];
                tower[j].emplace_back(arr[i]);
                in = 1;
                last = j+1;
                break;
            }
        }
        if(in == 0){
            tower[now].emplace_back(arr[i]);
            now++;
        }
        if(arr[i+1] < arr[i]) last = 0;
        in = 0;
    }
    printf("%d\n", now);

    return 0;
}
*/
