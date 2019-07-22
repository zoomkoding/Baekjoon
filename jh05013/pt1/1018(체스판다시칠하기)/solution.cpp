#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string chess1[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};

string chess2[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, MIN = 100;
    cin >> n >> m;
    string* board;
    string s;
    board = new string[n];
    for(int i = 0; i < n; i++)cin >> board[i];
    for(int i = 0; i <= n - 8; i++){
        for(int j = 0; j <= m - 8; j++){
            int c1 = 0, c2 = 0;
            for(int k = 0; k < 8; k++){
                for(int l = 0; l < 8; l++){
                    if(chess1[k][l] != board[i+k][j+l]) c1++;
                    if(chess2[k][l] != board[i+k][j+l]) c2++;
                }
            }
            MIN = min(MIN, min(c1, c2));
        }
    }
    cout << MIN;
}