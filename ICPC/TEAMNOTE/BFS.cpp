#include <cstdio>
#include <vector>
#include <queue>
#define pii pair<int, int>
using namespace std;

int t, m, n, k, x, y; 
int d[4][2]= { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int main(){
    scanf("%d", &t);
    while(t--){
        int cnt = 0;
        queue<pii> q;
        scanf("%d %d %d", &m, &n, &k);
        vector<vector<int> > v(m, vector<int>(n, 0));;
        while(k--){
            scanf("%d %d", &x, &y);
            v[x][y] = 1;
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(v[i][j] == 1){
                    q.push(pii(i, j));
                    v[i][j] = 0;
                    while(!q.empty()){
                        int fx = q.front().first, fy = q.front().second;
                        q.pop();
                        for(int k = 0; k < 4; k++){
                            int nx = fx + d[k][0], ny = fy + d[k][1];
                            if(nx >= m || nx < 0 || ny >= n || ny < 0 || !v[nx][ny])continue;
                            v[nx][ny] = 0;
                            q.push(pii(nx, ny));
                        }
                    }
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }   
}