/*
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
