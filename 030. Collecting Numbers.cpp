/*
Time limit: 1.00 s
Memory limit: 512 MB

You are given an array that contains each number between 1 \dots n exactly once. Your task is to collect the numbers from 1 to n in increasing order.
On each round, you go through the array from left to right and collect as many numbers as possible. What will be the total number of rounds?

Input
  The first line has an integer n: the array size.
  The next line has n integers x_1,x_2,\dots,x_n: the numbers in the array.
Output
  Print one integer: the number of rounds.
Constraints
  1 <= n <= 2 * 10^5

Example
  Input:
    5
    4 2 1 5 3
  Output:
    3
*/
// 從陣列中最小的數字開始取，可以取他往後的上升數字，需要幾次才能取完
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

struct number{
    int pos;
    int num;
    bool operator<(const number b) const {
        return num < b.num;
    }
};

int main(){

    vector<number> arr;
    int n, ans = 0;
    scanf("%d", &n);
    number tmp;
    for(int i = 0; i < n; i++){
        scanf("%d", &tmp.num);
        tmp.pos = i;
        arr.emplace_back(tmp);
    }
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++){
        while(arr[i].pos < arr[i+1].pos){
            i++;
        }
        ans++;
    }
    printf("%d\n", ans);

    return 0;
}
