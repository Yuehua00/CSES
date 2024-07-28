/*
Time limit: 1.00 s
Memory limit: 512 MB

You are given an array of n integers, and your task is to find four values (at distinct positions) whose sum is x.
Input
The first input line has two integers n and x: the array size and the target sum.
The second line has n integers a_1,a_2,\dots,a_n: the array values.
Output
Print four integers: the positions of the values. If there are several solutions, you may print any of them. If there are no solutions, print IMPOSSIBLE.
Constraints

1 \le n \le 1000
1 \le x,a_i \le 10^9

Example
Input:
8 15
3 2 5 8 1 3 2 3

Output:
2 4 6 7
*/
#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>
typedef long long int ll;

using namespace std;

struct Value{
    int num, pos;

    bool operator <(const Value& a)const{
        return a.pos < pos;
    }
};

bool compare(Value& a, Value& b){
    return a.num < b.num;
}

vector<Value> value;
ll n = 0, target = 0;

int main()
{
    scanf("%lld%lld", &n, &target);
    Value tmp;
    value.clear();
    bool ans = false;
    for(ll i = 0; i < n; i++){
        scanf("%lld", &tmp.num);
        tmp.pos = i+1;
        value.emplace_back(tmp);
    }
    sort(value.begin(), value.end(), compare);

    priority_queue<int, vector<int>, greater<int>> pq;
    for(ll i = 0; i < n-3 && !ans; i++){
        for(ll j = i+1; j < n-2 && !ans; j++){
            ll a = j+1, b = n-1;
            while(a < b) {
                ll sum = value[i].num + value[j].num + value[a].num + value[b].num;
                if(sum == target){
                    ans = true;
                    pq.push(value[i].pos); pq.push(value[j].pos); pq.push(value[a].pos); pq.push(value[b].pos);
                    while(!pq.empty()){
                        printf("%lld ", pq.top());
                        pq.pop();
                    }
                    printf("\n");
                    break;
                }else if(sum > target) b--;
                else a++;
            }

        }

    }
    if(!ans) printf("IMPOSSIBLE\n");


    return 0;
}
