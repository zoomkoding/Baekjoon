#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct Point{
    int x, y;
    Point(int i, int j){
        x = i;
        y = j;
    }
}Point;

int d[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int n, m, answer = 10000000;
int bfs(int l[][1010]){
    int v[1010][1010] = {0};
    for(int i = 0; i < n + 2; i++){
        for(int j = 0; j < m + 2; j++)v[i][j] = l[i][j];
    }
    queue<Point> q;
    q.push(Point(1, 1));
    while(!q.empty()){
        Point temp = q.front(); q.pop();
        int t = v[temp.x][temp.y];
        if(temp.x == n && temp.y == m){
            if(t < answer)answer = t;
            return 1;
        }
        for(int i = 0; i < 4; i++){
            int X = temp.x + d[i][0], Y = temp.y + d[i][1];
            if(v[X][Y] == 1){
                if(X == 1 && Y == 1)continue; 
                v[X][Y] = t + 1;
                q.push(Point(X, Y));
            }
        }
    }
    return 1;
}

int main(){
    scanf("%d %d ", &n, &m);
    int v[1010][1010] = {0,};
    for(int i = 0; i < n + 2; i++){
        if(i == 0 || i == n + 1) continue;
        for(int j = 1; j < m + 1; j++){
            char temp;
            scanf("%c", &temp);
            v[i][j] = '1' - temp;
        }
        getchar();
    }
    
    printf("%d", answer == 10000000 ? -1 : answer);
}