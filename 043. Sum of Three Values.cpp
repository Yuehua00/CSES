/*
想法來源 : https://www.youtube.com/watch?v=CfsvoiT6M5I&t=583s
Time limit: 1.00 s
Memory limit: 512 MB

You are given an array of n integers, and your task is to find three values (at distinct positions) whose sum is x.
Input
  The first input line has two integers n and x: the array size and the target sum.
  The second line has n integers a_1,a_2,\dots,a_n: the array values.
Output
  Print three integers: the positions of the values. If there are several solutions, you may print any of them. If there are no solutions, print IMPOSSIBLE.
Constraints
  1 <= n <= 5000
  1 <= x,a_i <= 10^9

Example
  Input:
    4 8
    2 7 5 1
  Output:
    1 3 4
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long int ull;

struct Value{
    int num;
    int pos;

    bool operator< (Value a) const{
        return num < a.num;
    }
};

int main() {

    ull n = 0, sum = 0;
    bool noans = true;
    scanf("%lld%lld", &n, &sum);
    vector<Value> values;
    Value t;
    for(ull i = 0; i < n; i++){
        scanf("%lld", &t.num);
        t.pos = i+1;
        values.emplace_back(t);
    }
    sort(values.begin(), values.end());

    ull first = 0, second = 0, third = 0;
    ull a = 0, b = a+1, c = n-1;
    for(a = 0; a < n; a++){
        c = n-1;
        for(b = a+1; b < c; b++){
            while(values[a].num + values[b].num + values[c].num > sum) c--;
            if(c <= b) break;
            // 輸出排序------------------------------------------------------------------------------------
            if(values[a].num + values[b].num + values[c].num == sum){
                if(values[a].pos > values[b].pos && values[a].pos > values[c].pos){
                    first = values[a].pos;
                    if(values[b].pos > values[c].pos){
                        second = values[b].pos;
                        third = values[c].pos;
                    }else{
                        second = values[c].pos;
                        third = values[b].pos;
                    }
                }else if(values[b].pos > values[a].pos && values[b].pos > values[c].pos){
                    first = values[b].pos;
                    if(values[a].pos > values[c].pos){
                        second = values[a].pos;
                        third = values[c].pos;
                    }else{
                        second = values[c].pos;
                        third = values[a].pos;
                    }
                }else if(values[c].pos > values[b].pos && values[c].pos > values[a].pos){
                    first = values[c].pos;
                    if(values[b].pos > values[a].pos){
                        second = values[b].pos;
                        third = values[a].pos;
                    }else{
                        second = values[a].pos;
                        third = values[b].pos;
                    }
                }
              //-------------------------------------------------------------------------------------------
                printf("%lld %lld %lld\n", third, second, first);
                noans = false;
                break;
            }
        }
    }
    if(noans){
        printf("IMPOSSIBLE\n");
    }

    return 0;
}
