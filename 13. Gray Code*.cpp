/*
Time limit: 1.00 s
Memory limit: 512 MB

A Gray code is a list of all 2^n bit strings of length n, where any two successive strings differ in exactly one bit (i.e., their Hamming distance is one).
Your task is to create a Gray code for a given length n.

Input
  The only input line has an integer n.
Output
  Print 2^n lines that describe the Gray code. You can print any valid solution.
Constraints
  1 <= n <= 16

Example
  Input:
    2
  Output:
    00
    01
    11
    10
*/
#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

typedef unsigned long long int ull;

int main()
{
    int n = 0;
    int arr[1000];
    memset(arr, 0, sizeof(arr));
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < pow(2, n); i++){
            ull y = i ^ (i >> 1);
            int cnt = 0;
            while(y > 1){
                arr[cnt] = y % 2;
                y /= 2;
                cnt++;
            }
            if(y == 1){
                arr[cnt] = 1;
            }else{
                cnt--;
            }
            for(int j = n-1; j >= 0; j--){
                printf("%d", arr[j]);
            }
            printf("\n");
        }
    }

    return 0;
}
