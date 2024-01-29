/*
Time limit: 1.00 s
Memory limit: 512 MB

You have to process n tasks. Each task has a duration and a deadline, and you will process the tasks in some order one after another. 
Your reward for a task is d-f where d is its deadline and f is your finishing time. 
(The starting time is 0, and you have to process all tasks even if a task would yield negative reward.)
What is your maximum reward if you act optimally?

Input
  The first input line has an integer n: the number of tasks.
  After this, there are n lines that describe the tasks. Each line has two integers a and d: the duration and deadline of the task.
Output
  Print one integer: the maximum reward.
Constraints
  1 <= n <= 2 * 10^5
  1 <= a,d <= 10^6

Example
  Input:
    3
    6 10
    8 15
    5 12
  Output:
    2
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long int ull;

struct task{
    ull deadline;
    ull finish_time;

    bool operator< (task a) const{
        return deadline < a.deadline;
    }
};

int main() {

    ull n = 0, ans = 0, now = 0;
    vector<task> tasks;
    task tmp;
    scanf("%lld", &n);
    for(ull i = 0; i < n; i++){
        scanf("%lld%lld", &tmp.deadline, &tmp.finish_time);
        tasks.emplace_back(tmp);
    }
    sort(tasks.begin(), tasks.end());

    for(ull i = 0; i < n; i++){
        ans += tasks[i].finish_time - (now + tasks[i].deadline);
        now += tasks[i].deadline;
    }
    printf("%lld\n", ans);

    return 0;
}
