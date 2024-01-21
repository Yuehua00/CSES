/*
Time limit: 1.00 s
Memory limit: 512 MB

Consider a game where there are n children (numbered 1,2,\dots,n) in a circle. 
During the game, every other child is removed from the circle until there are no children left. 
In which order will the children be removed?

Input
  The only input line has an integer n.
Output
  Print n integers: the removal order.
Constraints
  1 <= n <= 2 * 10^5

Example
  Input:
    7
  Output:
    2 4 6 1 5 3 7
*/
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(){

    int n = 0;
    scanf("%d", &n);
    multiset<int> pos;
    for(int i = 1; i<= n; i++){
        pos.insert(i);
    }
    auto child = pos.begin();
    int now = 0;
    child++;
    for(int i = 0; i < n; i++){
        printf("%d ", *child);
        now = *child;
        child++;
        pos.erase(now);
        if(child == pos.end() || (*child > n || *child < 1)){
            child = pos.begin();
        }
        if(!pos.empty()) child++;
        if(child == pos.end() || (*child > n || *child < 1)){
            child = pos.begin();
        }
    }
    printf("\n");

    return 0;
}
/* 其他做法
#include<iostream>
#include<queue>
 
using namespace std;

int main(){
    int n;
    cin >> n;
    deque<int> q;
    for(int i=0;i<n;i++) 
        q.push_back(i+1);
    while(q.size()!=1){
        q.push_back(q.front());
        q.pop_front();
        cout << q.front() << " ";
        q.pop_front();
    }
    cout << q.front() << endl;
}
*/
