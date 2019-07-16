#include <cstdio>
#include <vector>
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

vector<Point> p;
queue<Point > q;
int d[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

int bfs(vector<vector<int> > v){
    q.push(Point(1, 1));
    while(!q.empty()){
        Point temp = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int t = v[temp.x][temp.y];
            int X = temp.x + d[i][0], Y = temp.y + d[i][1];
            if(v[X][Y] == 1){
                if(X == 1 && Y == 1)continue;
                v[X][Y] = t + 1;
                q.push(Point(X, Y));
            }
        }
    }
}

int main(){
    int n, m;
    scanf("%d %d ", &n, &m);
    vector<vector<int> > v;
    v = vector<vector<int> >(n + 2);
    for(int i = 0; i < n + 2; i++){
        v[i] = vector<int>(m + 2);
        if(i == 0 || i == n + 1) continue;
        for(int j = 1; j < m + 1; j++){
            char temp;
            scanf("%c", &temp);
            v[i][j]= '1' - temp;
            if(v[i][j]) p.push_back(Point(i, j));
        }
        getchar();
    }    
    bfs(v);
    printf("%d", v[n][m]);
}
