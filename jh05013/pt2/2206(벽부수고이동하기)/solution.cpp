#include <cstdio>
#include <queue>
using namespace std;

typedef struct Point{
    int x, y;
    Point(int i, int j){
        x = i;
        y = j;
    }
}Point;

int v[1010][1010], dist[1010][1010], drill[1010][1010];
int d[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int n, m, answer = 10000000;

int bfs(){
    queue<Point> q;
    q.push(Point(0, 0));
    dist[0][0] = 1;
    while(!q.empty()){
        Point temp = q.front(); q.pop();
        int t = dist[temp.x][temp.y];
        int dr = drill[temp.x][temp.y];
        for(int i = 0; i < 4; i++){
            int X = temp.x + d[i][0], Y = temp.y + d[i][1];
            if(X >= n || Y >= m || X < 0 || Y < 0) continue;
            if(X == n - 1 && Y == m - 1)return t + 1;
            if(v[X][Y]){
                if(!dist[X][Y] || (drill[X][Y] && !dr)){
                    dist[X][Y] = t + 1;
                    drill[X][Y] = dr;
                    q.push(Point(X, Y));
                }
            }
            else if(!v[X][Y] && !drill[temp.x][temp.y]){
                dist[X][Y] = t + 1;
                drill[X][Y] = 1;
                q.push(Point(X, Y));
            }
        }
    }
    return -1;
}

int main(){
    scanf("%d %d ", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char temp;
            scanf("%c", &temp);
            v[i][j] = '1' - temp;
        }
        getchar();
    }
    if(n == 1 && m == 1) printf("1");
    else printf("%d", bfs());
}
