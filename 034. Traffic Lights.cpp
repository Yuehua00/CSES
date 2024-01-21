/*
Time limit: 1.00 s
Memory limit: 512 MB

There is a street of length x whose positions are numbered 0,1,\ldots,x.
Initially there are no traffic lights, but n sets of traffic lights are added to the street one after another.
Your task is to calculate the length of the longest passage without traffic lights after each addition.

Input
    The first input line contains two integers x and n: the length of the street and the number of sets of traffic lights.
    Then, the next line contains n integers p_1,p_2,\ldots,p_n: the position of each set of traffic lights. Each position is distinct.
Output
    Print the length of the longest passage without traffic lights after each addition.
Constraints
    1 <= x <= 10^9
    1 <= n <= 2 * 10^5
    0 < p_i < x

Example
    Input:
        8 3
        3 6 2
    Output:
        5 3 3
*/

// 小心得分享 : 自己想到的，跟網路解法一樣
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(){

    int n = 0, m = 0, a = 0;
    scanf("%d%d", &n, &m);
    multiset<int> pos, len;
    pos.insert(0);
    pos.insert(n);
    len.insert(n);
    for(int i = 0; i < m; i++){
        scanf("%d", &a);
        auto up = pos.upper_bound(a), down = pos.lower_bound(a);
        down--;
        //cout << *up << " " << *down << endl;
        auto erase_it = len.find(*up-*down);           // 因為 multiset 的 erase 會刪除所有相同 erase 當中的數字(如果指定數字)
        len.erase(erase_it);                          // 所以上一行先找到要刪除的數字的位置，利用迭代器，刪除特定位置的元素
        len.insert(*up-a);
        len.insert(a-*down);
        pos.insert(a);
        /*for(auto i : pos){
            cout << i << " ";
        }
        cout << endl;
        for(auto i : len){
            cout << i << " ";
        }
        cout << endl << endl;*/
        auto ans = len.end();
        ans--;
        printf("%d ", *ans);
    }
    printf("\n");

    return 0;
}

/* 第一版，會造成無法確認原本當中的長度是否有筆新增進來後切割的長度長
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(){

    int n = 0, m = 0, a = 0, ans = 0, start = 0, last = 0, mid = -1;
    scanf("%d%d", &n, &m);
    multiset<int> street;
    street.insert(n);
    street.insert(0);
    last = n;


    for(int i = 0; i < m; i++){
        scanf("%d", &a);
        auto up = street.upper_bound(a), down = street.lower_bound(a);
        down--;
        cout << *up << " " << *down << endl;
        if(*up <= last && *down >= mid && mid != -1){
            if(*up-a >= a-*down){
                ans = max(*up-a, ans);
                mid = a;
            }else{
                ans = max(a-*down, ans);
                last = a;
            }
        }else if(*up <= mid && *down >= start && mid != -1){
            if(*up-a <= a-*down){
                ans = max(a-*down, ans);
                mid = a;
            }else if(*up-a > a-*down){
                ans = max(*up-a, ans);
                start = a;
            }
        }else if(*up <= last && *down >= start){
            if(*up-a == a-*down){
                ans = *up-a;
                mid = a;
            }else if(*up-a > a-*down){
                ans = *up-a;
                start = a;
            }else{
                ans = a-*down;
                last = a;
            }
        }else{
            if(a-*down > *up-a && a-*down > ans){
                ans = a-*down;
                start = *down;
                last = a;
            }else if(*up-a > a-*down && *up-a > ans){
                ans = *up-a;
                start = a;
                last = *up;
            }

        }

        street.insert(a);
        printf("%d ", ans);
    }
    printf("\n");

    return 0;
}

*/
