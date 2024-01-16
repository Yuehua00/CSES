/*

*/
/*
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
