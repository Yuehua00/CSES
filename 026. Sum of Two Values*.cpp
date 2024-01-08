/*
Time limit: 1.00 s
Memory limit: 512 MB

You are given an array of n integers, and your task is to find two values (at distinct positions) whose sum is x.

Input
  The first input line has two integers n and x: the array size and the target sum.
  The second line has n integers a_1,a_2,\dots,a_n: the array values.
Output
  Print two integers: the positions of the values. If there are several solutions, you may print any of them. If there are no solutions, print IMPOSSIBLE.
Constraints
  1 <= n <= 2 * 10^5
  1 <= x,a_i <= 10^9

Example
  Input:
    4 8
    2 7 5 1
  Output:
    2 4
*/
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

typedef unsigned long long int ull;

int main(){

    multimap<int, int, greater<int>> num;   // 用 multiset 才能存前面重複數字 // greater<int> 是指由大到小排序，正常是放要排序的資料型態，但這裡的int好像抓成後面的(?)
    int n, x, a;
    scanf("%d%d", &n, &x);
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        num.insert({a, i+1});          // 用法注意 !
    }
    bool noans = true;
    for (auto i : num) {
        int complement = x - i.first;
        auto it = num.find(complement);
        if (it != num.end() && i.second != -1 && it->second != i.second) {   // it 用 -> ； i 用 .
            cout << it->second << " " << i.second << endl;
            it->second = -1;
            noans = false;
        }
    }
    if(noans){
        printf("IMPOSSIBLE\n");
    }

    return 0;
}
