#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#define pii pair<int, int>
using namespace std;

char map[52][52];
int ans, n, m, dist[52][52], d[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };


int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    memset(dist, -1, sizeof(dist));
    cin >> n >> m;
    for(int i = 0; i < n; i++)cin >> map[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] == 'W')continue;
            memset(dist, -1, sizeof(dist));
            queue<pii> q;
            dist[i][j] = 0;
            q.push(pii(i, j));
            while(!q.empty()){
                pii front = q.front(); q.pop();
                int fx = front.first, fy = front.second;
                for(int k = 0; k < 4; k++){
                    int nx = fx + d[k][0], ny = fy + d[k][1];
                    if(nx >= n || nx < 0 || ny >= m || ny < 0)continue;
                    if(dist[nx][ny] != -1)continue;
                    if(map[nx][ny] == 'W')continue;
                    q.push(pii(nx, ny));
                    dist[nx][ny] = dist[fx][fy] + 1;
                    if(dist[nx][ny] > ans)ans = dist[nx][ny];
                }
            }
        }
    }
    cout << ans;
}