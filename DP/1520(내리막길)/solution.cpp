#include <cstdio>
#include <queue>
#include <vector>
#define pii pair<int, int>
#define pip pair<int, pii>
using namespace std;

int n, m, arr[501][501], ans[501][501], visited[501][501], d[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)arr[i][j] = readInt();
    }
    priority_queue<pip, vector<pip>, less<pip> > pq;
    pq.push(pip(arr[0][0], pii(0, 0)));
    ans[0][0] = 1;
    visited[0][0] = 1;
    while(!pq.empty()){
        pip top = pq.top(); pq.pop();
        int tv = top.first, tx = top.second.first, ty = top.second.second;
        for(int i = 0; i < 4; i++){
            int nx = tx + d[i][0], ny = ty + d[i][1];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
            if(arr[nx][ny] < tv) {
                ans[nx][ny] += ans[tx][ty];
                if(!visited[nx][ny]){
                    visited[nx][ny] = 1;
                    pq.push(pip(arr[nx][ny], pii(nx, ny)));
                }
            }
        }
    }
    printf("%d", ans[n-1][m-1]);
    
}