#include <cstdio>
#include <queue>
#include <vector>
#define pii pair<int, int>

using namespace std;

int n, arr[101][101], sinked[101][101], visited[101][101], MAX;
int d[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int main(){
    scanf("%d", &n);
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < n + 1; j++)scanf("%d", &arr[i][j]);
    }
    for(int k = 1; k < 101; k++){
        for(int i = 1; i < n + 1; i++){
            for(int j = 1; j < n + 1; j++){
                visited[i][j] = 0;
                if(arr[i][j] < k)sinked[i][j] = 0;
                else sinked[i][j] = 1;
            }
        }
        int cnt = 0;
        for(int i = 1; i < n + 1; i++){
            for(int j = 1; j < n + 1; j++){
                if(sinked[i][j] && !visited[i][j]){
                    queue<pii> q;
                    q.push(pii(i,j));
                    visited[i][j] = 1;
                    while(!q.empty()){
                        int fx = q.front().first, fy = q.front().second; q.pop();
                        for(int i = 0; i < 4; i++){
                            int nx = fx + d[i][0], ny = fy + d[i][1];
                            if(!sinked[nx][ny] || visited[nx][ny]) continue;
                            visited[nx][ny] = 1;
                            q.push(pii(nx, ny));
                        }
                    }
                    cnt++;
                }
            }
        }
        if(cnt > MAX)MAX = cnt;
    }
    printf("%d", MAX);
}