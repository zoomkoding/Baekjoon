//풀이는 아래 블로그를 참고해주세요!
//zoomkoding.github.io/codingtest/2019/07/30/baekjoon-1261.html

#include <cstdio>
#include <vector>
#include <queue>
#define pii pair<int, int>
#define X first
#define Y second
using namespace std;

int main(){
    char miro[102][102];
    int d[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
    int cnt[102][102];
    int n, m, tw, tx, ty, nw, nx, ny;
    queue<pii> p;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m ; i++){
        for(int j = 0; j < n; j++){
            scanf("%1d", &miro[i][j]);
            cnt[i][j] = 1000;
        }
    } 
    cnt[0][0] = miro[0][0];
    p.push({0, 0});
    while(!p.empty()){
        pii top = p.front(); p.pop();
        tx = top.X, ty = top.Y;
        for(int i = 0; i < 4; i++){
            nx = tx + d[i][0], ny = ty + d[i][1];
            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if(cnt[nx][ny] > cnt[tx][ty] + miro[nx][ny]){
                cnt[nx][ny] = cnt[tx][ty] + miro[nx][ny];
                p.push({nx, ny});
            }
        }
    }
    printf("%d", cnt[m-1][n-1]);
}