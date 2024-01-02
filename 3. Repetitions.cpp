/*
Time limit: 1.00 s
Memory limit: 512 MB

You are given a DNA sequence: a string consisting of characters A, C, G, and T. Your task is to find the longest repetition in the sequence. 
This is a maximum-length substring containing only one type of character.

Input
  The only input line contains a string of n characters.
Output
  Print one integer: the length of the longest repetition.
Constraints
  1 <= n <= 10^6

Example
  Input:
    ATTCGGGA
  Output:
    3
*/

#include <iostream>

using namespace std;

typedef unsigned long long int ull;

int main()
{

    string s;
    char tmp = 'l';
    int cnt = 0, ans = 0;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != tmp){
            if(cnt > ans){
                ans = cnt;
            }
            tmp = s[i];
            cnt = 1;
        }
        else cnt++;
    }
    if(cnt > ans){
        ans = cnt;
    }
    printf("%d\n", ans);


    return 0;
}
