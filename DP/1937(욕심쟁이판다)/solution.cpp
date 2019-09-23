#include <cstdio>
#include <vector>
#include <queue>
#define pii pair<int, int>
#define pip pair<int, pii>
using namespace std;
int ans, n, arr[501][501], d[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)scanf("%d", &arr[i][j]);
    }
    priority_queue<pip, vector<pip>, less<pip> > pq;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int visited[501][501] = {0,}, v[501][501] = {0,};
            visited[i][j] = 1;
            v[i][j] = 1;
            pq.push(pip(arr[i][j], pii(i, j)));
            while(!pq.empty()){
                pip top = pq.top(); pq.pop();
                int tv = top.first, tx = top.second.first, ty = top.second.second;
                for(int k = 0; k < 4; k++){
                    int nx  = tx + d[k][0], ny = ty + d[k][1];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
                    if(arr[nx][ny] < tv){
                        if(!visited[nx][ny]){
                            pq.push(pip(arr[nx][ny], pii(nx, ny)));
                        }
                        if(v[nx][ny] < v[tx][ty] + 1){
                            v[nx][ny] = v[tx][ty] + 1;
                            if(v[nx][ny] > ans)ans = v[nx][ny];
                        }

                    }
                }
            }
        }
    }
    printf("%d", ans);
}