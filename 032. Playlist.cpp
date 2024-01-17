// 來源 : https://www.youtube.com/watch?app=desktop&v=CkJRXaQw8BA
/*
Time limit: 1.00 s
Memory limit: 512 MB

You are given a playlist of a radio station since its establishment. The playlist has a total of n songs.
What is the longest sequence of successive songs where each song is unique?

Input
    The first input line contains an integer n: the number of songs.
    The next line has n integers k_1,k_2,\ldots,k_n: the id number of each song.
Output
    Print the length of the longest sequence of unique songs.
Constraints
    1 <= n <= 2 * 10^5
    1 <= k_i <= 10^9

Example
    Input:
        8
        1 2 1 3 2 7 4 2
    Output:
        5
*/

#include <iostream>
#include <algorithm>
#include <set>         // 利用 set 不是 queue 的原因是因為 set 才能用 count 回傳是否存在某個元素

using namespace std;

int main(){

    int n = 0, ans = 0, start = 0;
    scanf("%d", &n);
    int arr[n+5];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    set<int> s;
    for(int i = 0; i < n; i++){
        while(s.count(arr[i])){   // 當這個要新增的元素已存在原本的子字串中則從頭開始刪除直到要新增的元素被刪除
            s.erase(arr[start]);
            start++;
        }
        s.insert(arr[i]);
        ans = max(ans, (int)s.size());
    }
    printf("%d\n", ans);

    return 0;
}

/*自記寫的，計算兩個相同數字當中最長距離則為答案；沒辦法檢查是否存在其他相同數字是否存在(例如計算兩個1之間的長度無法卻是是否存在兩個或以上的2或其他數字)
#include <iostream>
#include <algorithm>

using namespace std;

struct song{
    int length;
    int pos;

    bool operator<(song b)const{
        return length < b.length;
    }
};

int main(){

    int n = 0, ans = 0, cnt = 0, dif = 0, num = 0, first = 0;
    scanf("%d", &n);
    song arr[n+5];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i].length);
        arr[i].pos = i;
        if(first == 0) first = arr[i].length;
        if(arr[i].length != first) num++;
    }
    if(num == 0){
        printf("1\n");
    }else{
        sort(arr, arr+n);

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(arr[i].length == arr[j].length){
                    ans = max(ans, arr[j].pos-arr[i].pos-1);
                    cnt++;
                }else{
                    if(cnt == 0){
                       ans++;
                       dif++;
                    }
                    j--;
                    if(j-i-1 > 0) i += j-i-1;
                    break;
                }
            }
            cnt = 0;
        }
        if(ans == 0 || dif == n-1) ans = n;
        else if(dif == 0) ans = 1;
        printf("%d\n", ans);
    }


    return 0;
}
*/
