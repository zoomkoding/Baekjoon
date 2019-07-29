#include <cstdio>
#include <cmath>

int n, cnt, board[15];

void find(int x, int q){
    if(q == n){
        cnt ++;
        return;
    }
    
    for(int i = 1; i < n + 1; i++){
        int isvalid = 1;
        for(int k = 1; k < x; k++){
            if(board[k] == i || abs(x - k) == abs(i - board[k])) isvalid = 0;
        }
        if(isvalid) {
            board[x] = i; 
            find(x + 1, q + 1);
            board[x] = 0;
        }
    }
    
}

int main(){
    scanf("%d", &n);
    find(1, 0);
    printf("%d", cnt);
}

