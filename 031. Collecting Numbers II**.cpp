/*
來源 : https://coding-prep.com/2023/02/03/cses-collecting-numbers-ii/

Time limit: 1.00 s
Memory limit: 512 MB

You are given an array that contains each number between 1 \dots n exactly once. Your task is to collect the numbers from 1 to n in increasing order.
On each round, you go through the array from left to right and collect as many numbers as possible.
Given m operations that swap two numbers in the array, your task is to report the number of rounds after each operation.

Input
  The first line has two integers n and m: the array size and the number of operations.
  The next line has n integers x_1,x_2,\dots,x_n: the numbers in the array.
  Finally, there are m lines that describe the operations. Each line has two integers a and b: the numbers at positions a and b are swapped.
Output
  Print m integers: the number of rounds after each swap.
Constraints
  1 <= n, m <= 2 * 10^5
  1 <= a,b <= n

Example
  Input:
    5 3
    4 2 1 5 3
    2 3
    1 5
    2 3
  Output:
    2
    3
    4
*/
#include <iostream>

using namespace std;

int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    int a[n+1], idx[n+2];
    idx[0] = 0, idx[n+1] = n+1;
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
        idx[a[i]] = i;
    }
    int cnt = 1;
    for(int i = 1;i <= n;i++){
        if(idx[i] <= idx[i-1])
            cnt++;
    }

    while(q--){
        int l, r;
        scanf("%d%d", &l, &r);
        int x = a[l], y = a[r];

        swap(a[l], a[r]);
        if (idx[x-1] <= idx[x] && idx[x-1] > r) cnt++; // 前一個比我小的數字原本在我前面，但會在我之後的位子之後
        if (idx[x-1] > idx[x] && idx[x-1] <= r) cnt--; // 前一個比我小的在我後面，但會在我之後的位子之前
        if (idx[x] <= idx[x+1] && r > idx[x+1]) cnt++; // 後一個比我大的數字原本在我後面，但會在我之後的位子前面
        if (idx[x] > idx[x+1] && r <= idx[x+1]) cnt--; // 後一個比我大的數字原本在我前面，但會在我之後的位子的後面
        idx[x] = r;
        if (idx[y-1] <= idx[y] && idx[y-1] > l) cnt++;
        if (idx[y-1] > idx[y] && idx[y-1] <= l) cnt--;
        if (idx[y] <= idx[y+1] && l > idx[y+1]) cnt++;
        if (idx[y] > idx[y+1] && l <= idx[y+1]) cnt--;
        idx[y] = l;

        printf("%d\n", cnt);
    }
}
/* 自己寫的會超時
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
 
using namespace std;
 
typedef unsigned long long int ull;
typedef long long int ll;
 
struct number{
    int pos;
    int num;
};
 
bool compare_pos(number a, number b){
    return a.pos < b.pos;
}
 
bool compare_num(number a, number b){
    return a.num < b.num;
}
 
int main(){
 
    vector<number> arr, ori;
    int n, m, ans = 0;
    scanf("%d%d", &n, &m);
    number tmp;
    for(int i = 0; i < n; i++){
        scanf("%d", &tmp.num);
        tmp.pos = i;
        arr.emplace_back(tmp);
    }
    ori = arr;
    //sort(arr.begin(), arr.end());
    int a, b;
    for(int j = 0; j < m; j++){
        ans = 0;
        scanf("%d%d", &a, &b);
        ori[a-1].pos = b-1;
        ori[b-1].pos = a-1;
        swap(ori[a-1], ori[b-1]);
        //sort(ori.begin(), ori.end(), compare_pos);
        arr = ori;
        sort(arr.begin(), arr.end(), compare_num);     // sort 和下面的 for 迴圈造成的
        for(int i = 0; i < n; i++){
            while(arr[i].pos < arr[i+1].pos){
                i++;
            }
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
*/
