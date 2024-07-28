/*
Time limit: 1.00 s 
Memory limit: 512 MB

Your task is to place eight queens on a chessboard so that no two queens are attacking each other.
As an additional challenge, each square is either free or reserved, and you can only place queens on the free squares. 
However, the reserved squares do not prevent queens from attacking each other.
How many possible ways are there to place the queens?

Input
  The input has eight lines, and each of them has eight characters. Each square is either free (.) or reserved (*).
Output
  Print one integer: the number of ways you can place the queens.

Example
  Input:
    ........
    ........
    ..*.....
    ........
    ........
    .....**.
    ...*....
    ........
  Output:
    65
*/
#include <iostream>
#include <cstring>

using namespace std;

int place[8+5];
char chessboard[8+5][8+5];
int ans = 0;


bool conflict(int x, int y){
    if(chessboard[x][y] == '*') return true;
    for(int i = 0; i < x; i++){
        if(place[i] == y) return true;               // 橫線
        if(abs(x-i) == abs(place[i]-y)) return true; // 斜線
    }
    return false;
}

void queens(int q){

    if(q == 8){
       ans++;
       return;
    }
    for(int i = 0; i < 8; i++){
        if(!conflict(q, i)){
            place[q] = i;
            queens(q+1);
        }
    }

}

int main(){

    memset(place, -1, sizeof(place));
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin >> chessboard[i][j];
        }
    }
    queens(0);
    printf("%d\n", ans);

    return 0;
}
