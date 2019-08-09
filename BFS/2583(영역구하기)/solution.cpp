#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#define pii pair<int, int>

using namespace std;

int n, m, k, x1, y1, x2, y2, arr[100][100];
int d[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int main(){
    queue<pii> q;
    vector<int> ans;
    scanf("%d %d %d", &m, &n, &k);
    while(k--){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for(int i = x1; i < x2; i++){
            for(int j = y1; j < y2; j++)arr[i][j] = 1; 
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 0){
                int cnt = 1;
                q.push(pii(i,j));
                arr[i][j] = 1;
                while(!q.empty()){
                    int fx = q.front().first, fy = q.front().second;
                    q.pop();
                    for(int k = 0; k < 4; k++){
                        int nx = fx + d[k][0], ny = fy + d[k][1];
                        if(nx >= n || ny >= m || nx < 0 || ny < 0)continue;
                        if(arr[nx][ny])continue;
                        arr[nx][ny] = 1;
                        cnt ++;
                        q.push(pii(nx, ny));
                    }
                }
                ans.push_back(cnt);
            }
        }
    }
    sort(ans.begin(), ans.end());
    int s = ans.size();
    printf("%d\n", s);
    for(int i = 0; i < s; i++)printf("%d ", ans[i]);
}