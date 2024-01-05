/*
Time limit: 1.00 s
Memory limit: 512 MB

Given a string, your task is to reorder its letters in such a way that it becomes a palindrome (i.e., it reads the same forwards and backwards).

Input
  The only input line has a string of length n consisting of characters A–Z.
Output
  Print a palindrome consisting of the characters of the original string. You may print any valid solution. If there are no solutions, print "NO SOLUTION".
Constraints
  1 <= n <= 10^6

Example
  Input:
    AAAACACBA
  Output:
    AACABACAA
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string.h>

using namespace std;

typedef unsigned long long int ull;

int main()
{
    string s;
    int arr[25+5];
    memset(arr, 0, sizeof(arr));
    int total = 0;
    while(cin >> s){
        for(int i = 0; i < s.length(); i++){
            if(arr[(s[i]-'A')] == 0) total++;
            arr[(s[i]-'A')]++;
        }
        int cnt = 0;
        for(int i = 0; i < 26; i++){
            if(arr[i] % 2 == 1) cnt++;
        }
        if(cnt > 1){
            printf("NO SOLUTION\n");
            break;
        }
        int a = 0, b = s.length()-1, c = (a+b) / 2;
        int now = 0;
        for(int i = 0; i < 26; i++){
            if(now == total){
              break;
            }
            if (arr[i] > 0) now++;
            while(arr[i] > 1){
                s[a] = i+'A';
                s[b] = i+'A';
                a++;
                b--;
                arr[i] -= 2;
            }
            if(arr[i] != 0){
                s[c] = i+'A';
            }
        }
        cout << s << endl;

    }

    return 0;
}
