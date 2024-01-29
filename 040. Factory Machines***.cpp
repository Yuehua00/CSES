// 來源 : youtube.com/watch?v=OmH_BRMOXmg

/*
Time limit: 1.00 s
Memory limit: 512 MB

A factory has n machines which can be used to make products. Your goal is to make a total of t products.
For each machine, you know the number of seconds it needs to make a single product. The machines can work simultaneously, and you can freely decide their schedule.
What is the shortest time needed to make t products?

Input
  The first input line has two integers n and t: the number of machines and products.
  The next line has n integers k_1,k_2,\dots,k_n: the time needed to make a product using each machine.
Output
  Print one integer: the minimum time needed to make t products.
Constraints
  1 <= n <= 2 * 10^5
  1 <= t <= 10^9
  1 <= k_i <= 10^9

Example
  Input:
    3 7
    3 2 5
  Output:
    8
Explanation: Machine 1 makes two products, machine 2 makes four products and machine 3 makes one product.
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long int ull;

int main() {

    ull n = 0, m = 0, a = 0;
    scanf("%lld%lld", &n, &m);
    vector<int> machines;
    for(ull i = 0; i < n; i++){
        scanf("%lld", &a);
        machines.emplace_back(a);
    }
    sort(machines.begin(), machines.end());

    ull low = 0, high = 1e18, answer = 1e18;
    while(low <= high){
        ull mid = (low + high) / 2;
        ull products = 0;
        for(int i = 0; i < n; i++){
            products += min(mid/machines[i], (ull)1e9);
            
            // mid 表示的是總時間， machines[i] 表示的是第 i 台機器的生產速率 -> mid/machines[i] = 機器在時間 mid 內的生產次數
            // 因為題目中限制了產品數量必須是 1e9 以內，所以這裡使用 (ull)1e9 來將其轉換為 ull 型別，即無符號長整數型別，以避免溢出
        }
        if(products >= m){
            if(mid < answer){
                answer = mid;
            }
            high = mid - 1;
        }else low = mid + 1;

    }
    printf("%lld\n", answer);

    return 0;
}
