// priority_queue 來源 : https://usaco.guide/problems/cses-1164-room-allocation/solution

/*
Time limit: 1.00 s
Memory limit: 512 MB

There is a large hotel, and n customers will arrive soon. Each customer wants to have a single room.
You know each customer's arrival and departure day. Two customers can stay in the same room if the departure day of the first customer is earlier than the arrival day of the second customer.
What is the minimum number of rooms that are needed to accommodate all customers? And how can the rooms be allocated?

Input
  The first input line contains an integer n: the number of customers.
  Then there are n lines, each of which describes one customer. Each line has two integers a and b: the arrival and departure day.
Output
  Print first an integer k: the minimum number of rooms required.
  After that, print a line that contains the room number of each customer in the same order as in the input. The rooms are numbered 1,2,\ldots,k. You can print any valid solution.
Constraints
  1 <= n <= 2 * 10^5
  1 <= a <= b <= 10^9

Example
  Input:
    3
    1 2
    2 4
    4 4 
  Output:
    2
    1 2 1
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int ans[200005];

struct people{
    int arrive;
    int leave;
    int number;

    bool operator<(people a) const{
        return arrive < a.arrive;
    }
};

int main() {

    int n = 0;
    scanf("%d", &n);
    vector<people> customers;
    people tmp;
    for(int i = 0; i < n; i++){
        scanf("%d%d", &tmp.arrive, &tmp.leave);
        tmp.number = i;
        customers.emplace_back(tmp);
    }
    sort(customers.begin(), customers.end());

    priority_queue<pair<int, int>> pq;
    int rooms = 0, last_room = 0;
    for(int i = 0; i < n; i++){
        if(pq.empty()){
            last_room++;
            pq.push(make_pair(-customers[i].leave, last_room));
            ans[customers[i].number] = last_room;
        }else{
            pair<int, int> minimum = pq.top();
            if(-minimum.first < customers[i].arrive){
                pq.pop();
                pq.push(make_pair(-customers[i].leave, minimum.second));
                ans[customers[i].number] = minimum.second;
            }else{
                last_room++;
                pq.push(make_pair(-customers[i].leave, last_room));
                ans[customers[i].number] = last_room;
            }
        }
        rooms = max(rooms, (int)pq.size());
    }

    printf("%d\n", rooms);
    for(int i = 0; i < n; i++){
        printf("%d ", ans[i]);
    }
    printf("\n");


    return 0;
}
