#include <cstdio>
#include <queue>
using namespace std;

typedef struct info{
    int rx, ry, bx, by, cnt;
    info(int i, int j, int k, int l, int m){
        rx = i, ry = j, bx = k, by = l, cnt = m;
    }
    info();
}info;

int n, m, board[11][11], rx, ry, bx, by;
int d[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int main(){
    queue<info> q; 
    scanf("%d %d ", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char temp;
            scanf("%c", &temp);
            if(temp == '.' || temp == 'B' || temp == 'R') board[i][j] = 0;
            else if(temp == 'O')board[i][j] = -2;
            else board[i][j] = -1;
            if(temp == 'B')bx = j, by = i;
            else if(temp == 'R')rx = j, ry = i;
        }
        getchar();
    }
    q.push(info(rx, ry, bx, by, 0));
    while(!q.empty()){
        info front = q.front(); q.pop();
        int frx = front.rx, fry = front.ry, fbx = front.bx, fby = front.by, cnt = front.cnt; 
        if(cnt >= 10) continue;
        for(int i = 0; i < 4; i++){
            int nrx = frx, nry = fry, nbx = fbx, nby = fby, end = 0, cnt_r = 0, cnt_b = 0;
            while(board[nby + d[i][0]][nbx + d[i][1]]!= -1){
                nbx += d[i][1], nby += d[i][0];
                cnt_b ++;
                if(board[nby][nbx] == -2){
                    end -= 2;
                    break;
                }
            }
            if(end < 0) continue;
            while(board[nry + d[i][0]][nrx + d[i][1]]!= -1){
                nrx += d[i][1], nry += d[i][0];
                cnt_r ++;
                if(board[nry][nrx] == -2){
                    end ++;
                    break;
                }
            }
            if(nrx == nbx && nry == nby){
                if(cnt_r < cnt_b)nbx -= d[i][1], nby -= d[i][0];
                else nrx -= d[i][1], nry -= d[i][0];
            }
            if(end){
                if(cnt > 10) printf("-1");
                else printf("%d", cnt + 1);
                return 0;
            }
            q.push(info(nrx, nry, nbx, nby, cnt + 1));
        }
    }
    printf("-1");    
}