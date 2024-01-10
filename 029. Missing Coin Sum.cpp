/*
Time limit: 1.00 s
Memory limit: 512 MB

You have n coins with positive integer values. What is the smallest sum you cannot create using a subset of the coins?

Input
  The first input line has an integer n: the number of coins.
  The second line has n integers x_1,x_2,\dots,x_n: the value of each coin.
Output
  Print one integer: the smallest coin sum.
Constraints
  1 <= n <= 2 * 10^5
  1 <= x_i <= 10^9

Example
  Input:
    5
    2 9 1 2 7
  Output:
    6
*/
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

int main(){

    int n = 0;
    scanf("%d", &n);
    int arr[n+5];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+n);
    ll nowb = 0, cana = 0, canb = 0, ans = 0, have = 0;
    bool have_one = false;
    for(int i = 0; i < n; i++){
        if(arr[i] == 1){
            have_one = true;
        }
        if(have_one == false){    // 沒有1直接輸出
            printf("1\n");
            have = 1;
            break;
        }
        cana = arr[i];                       // cana ~ canb = 自己到目前為止(nowb)+自己
        canb = arr[i] + nowb;
        if(nowb == 0 || cana - nowb <= 1){   // 如果 cana <= nowb ( cana 包還在目前可以達成的範圍內) 則更新可以範圍
            nowb = canb;
        }
        if(cana - nowb > 1){  // 如果 nowb 和 cana 有差距，表示出現無法達成的數字
            ans = nowb+1;
        }
        if(ans != 0){
            printf("%lld\n", ans);
            have = 1;
            break;
        }
    }
    if(have == 0){
        printf("%lld\n", nowb+1);
    }

    return 0;
}

/*其他人作法

if(arr[0] > 1){
  cout << "1\n";
}
ll R = 0;
for(int i = 0; i < n; i++){
  if(R+1 < arr[i]){
    cout << R+1 << endl;
    have = 1;
    break;
  }
  R += arr[i];
}
if(have == 0){
  cout << R+1 << endl;
}
*/
