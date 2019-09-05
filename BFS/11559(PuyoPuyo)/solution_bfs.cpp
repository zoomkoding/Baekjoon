#include <cstdio>
#include <queue>
#include <vector>
#define pii pair<int, int>
using namespace std;

int d[4][2] = { {0, -1}, {-1, 0}, {1, 0}, {0, 1} };
int mem[90][2];
char board[12][7];

int bfs(int x, int y, int visited[][6]){
    int cnt = 1;
    mem[0][0] = x, mem[0][1] = y;
    queue<pii> q;
    visited[x][y] = 1;
    q.push(pii(x, y));
    while(!q.empty()){
        pii front = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int nx = front.first + d[i][0], ny = front.second + d[i][1];
            if(visited[nx][ny] || board[nx][ny] != board[x][y]) continue;
            visited[nx][ny] = 1;
            mem[cnt][0] = nx, mem[cnt][1] = ny;
            cnt++;
            q.push(pii(nx, ny));
        }
    }
    if(cnt >= 4){
        for(int i = 0; i < cnt; i++) board[mem[i][0]][mem[i][1]] = 'a';
    }
    return cnt;
}

void adjust(){
    for(int j = 0; j < 6; j++){
        int move = 0;
        for(int i = 10; i >= 0; i--){
            if(board[i+move][j] =='.')break;
            if(board[i+1][j]=='a')move++;
            board[i+move][j] = board[i][j];
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
        int pass = 0, visited[12][6] = {0,};
        for(int i = 0; i < 12; i++){
            for(int j = 0; j < 6; j++){
                if(board[i][j] != '.' && !visited[i][j]){
                    if(bfs(i, j, visited)>=4) pass = 1;
                }
            }
        }
        if(pass){
            ans++;
            adjust();
        }
        else break;
    }
    printf("%d", ans);
}