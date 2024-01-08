/*
Time limit: 1.00 s
Memory limit: 512 MB

In a movie festival n movies will be shown. You know the starting and ending time of each movie. 
What is the maximum number of movies you can watch entirely?

Input
  The first input line has an integer n: the number of movies.
  After this, there are n lines that describe the movies. Each line has two integers a and b: the starting and ending times of a movie.
Output
  Print one integer: the maximum number of movies.
Constraints
  1 <= n <= 2 * 10^5
  1 <= a < b <= 10^9

Example
  Input:
    3
    3 5
    4 9
    5 8
  Output:
    2
*/
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

typedef unsigned long long int ull;

int main(){

    set<pair<int, int>> time;
    int n, start, endm;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &start, &endm);
        time.insert(make_pair(start, endm));
    }
    int cnt = 0, now = 0, endn = 0;
    for(auto it : time){
        if(endn <= it.first){
            now = it.first;
            endn = it.second;
            cnt++;
        }else if(now <= it.first && (it.second-it.first) < (endn - now) && endn >= it.second){   // 更換成看時長比較短的電影
            now = it.first;
            endn = it.second;
        }
    }
    printf("%d\n", cnt);

    return 0;
}
