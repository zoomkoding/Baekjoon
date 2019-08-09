#include <cstdio>
#include <vector>
#include <queue>
#define pii pair<int, int>
using namespace std;


int d[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int n, m, arr[8][8], MAX;

void bfs(){
    int check[8][8] = {0,};
    queue<pii> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)check[i][j] = arr[i][j];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(check[i][j] == 2){
                q.push(pii(i, j));
                while(!q.empty()){
                    int fx = q.front().first, fy = q.front().second;
                    q.pop();
                    for(int i = 0; i < 4; i++){
                        int nx = fx + d[i][0], ny = fy + d[i][1];
                        if(nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
                        if(check[nx][ny] == 1)continue;
                        check[nx][ny] = 1;
                        q.push(pii(nx, ny));
                    }
                }
            }       
        }
    }
    
    
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!check[i][j]) cnt++;
        }
    }
    if(cnt > MAX)MAX = cnt;
}

void dfs(int x, int y, int cnt){
    if(cnt == 3){
        bfs();
        return;
    }
    for(int j = y; j < m; j++){
        if(arr[x][j] == 0) {
            arr[x][j] = 1;
            dfs(x, j, cnt + 1);
            arr[x][j] = 0;
        }
    }
    for(int i = x + 1; i < n; i++){
        for(int j = 0 ; j < m; j++){
            if(arr[i][j] == 0) {
                arr[i][j] = 1;
                dfs(i, j, cnt + 1);
                arr[i][j] = 0;
            }
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)scanf("%d", &arr[i][j]);
    }
    dfs(0, 0, 0);
    printf("%d", MAX);
}