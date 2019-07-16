#include <cstdio>

typedef struct Point{
    int x, y;
    Point(int i, int j){
        x = i;
        y = j;
    }
}Point;

int n = 0, sudoku[9][9];
Point v[81];

int backtrack(int c){   
    if(c == n) return 1;
    int cnt[10] = {0,};
    int X = v[c].x, Y = v[c].y, result = 0;
    int sx = (X / 3) * 3, sy = (Y / 3) * 3;
    for(int i = sx; i < sx + 3; i++){
        for(int j = sy; j < sy + 3; j++) cnt[sudoku[i][j]] = 1;
    }
    for(int i = 0; i < 9; i++) cnt[sudoku[X][i]] = cnt[sudoku[i][Y]] = 1;
    
    for(int i = 1; i < 10; i++){
        if(cnt[i] == 0) {
            sudoku[X][Y] = i;
            result = backtrack(c+1);
            if(result) break;
            sudoku[X][Y] = 0;
        }
    }
    return result;
}

int main(){
    for(int i = 0; i < 9; i ++){
        for(int j = 0; j < 9; j++){
            scanf("%d", &sudoku[i][j]);
            if(!sudoku[i][j]) v[n++] = Point(i, j);      
        }
    }
    backtrack(0);
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++) printf("%d ", sudoku[i][j]);
        printf("\n");
    }
}
