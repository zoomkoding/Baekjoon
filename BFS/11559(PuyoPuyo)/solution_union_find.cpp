#include <cstdio>

int d[4][2] = { {0, -1}, {-1, 0}, {1, 0}, {0, 1} };
typedef struct info{
    int x, y;
    info(){
        x = -1, y = -1;
    }
    info(int i, int j){
        x = i, y = j;
    }
}info;

info parent[12][7];
int cnt[12][7];
char board[12][7];

info find(int i, int j){
    if(parent[i][j].x == i && parent[i][j].y == j)return info(i, j);
    else return find(parent[i][j].x, parent[i][j].y);
}

void Union(int x1, int y1, int x2, int y2){
    info p1 = find(x1, y1), p2 = find(x2, y2);
    if(p1.x == p2.x && p1.y == p2.y) return;
    parent[x2][y2] = p1;    
    parent[p2.x][p2.y] = p1;
}

void adjust(int x, int y){
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 6; j++){
            info par = parent[i][j];
            if(par.x == x && par.y == y){
                for(int k = i; k >= 1; k--)board[k][j] = board[k-1][j];
            }
        }
    }
}

int main(){
    int ans = 0;
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 7; j++){
            scanf("%c", &board[i][j]);
        }
    }
    while(1){
        for(int i = 0; i < 12; i++){
            for(int j = 0; j < 6; j++){
                cnt[i][j] = 0;
                parent[i][j] = info(i, j);
            }
        }
        for(int i = 0; i < 12; i++){
            for(int j = 0; j < 6; j++){
                char r = board[i][j];
                if(r == '.')continue;
                for(int k = 0; k < 2; k++){
                    if(i+d[k][0] < 0 || j+d[k][1] < 0 || i+d[k][0] > 11 || j+d[k][1] > 5) continue;
                    if(board[i+d[k][0]][j+d[k][1]] == r){
                        Union(i+d[k][0], j+d[k][1], i, j);
                    }
                }
            }
        }
        int pass = 0;
        for(int i = 0; i < 12; i++){
            for(int j = 0; j < 6; j++){
                info par = find(i, j);
                parent[i][j] = par;
                cnt[par.x][par.y] ++;
            }
        }
        for(int i = 0; i < 12; i++){
            for(int j = 0; j < 6; j++){
                if(cnt[i][j] >= 4){
                    pass = 1;
                    adjust(i, j);
                }
            }
        }
        ans += pass;
        if(!pass)break;
    }
    printf("%d", ans);
}