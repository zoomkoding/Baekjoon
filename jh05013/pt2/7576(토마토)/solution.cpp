#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int d[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int x, y, m = 0, n = 0;
    scanf("%d %d", &x, &y);
    vector<vector<int> >v(y + 2); 
    queue<pair<int, int> > q;
    for(int i = 0; i < y + 2; i++){
        v[i] = vector<int>(x+2);
        for(int j = 0; j < x + 2; j++){
            if(i == 0 || j == 0 || i == y + 1 || j == x + 1)v[i][j] = -1;
            else{
                scanf("%d", &v[i][j]);
                if(v[i][j] == 1)q.push(make_pair(i, j));
                else if(v[i][j] == 0) n++;
            }
        }
    }
    if(n == 0){
        printf("0");
        return 0;
    }
    while(!q.empty()){
        pair<int, int> temp = q.front(); q.pop();
        int time = v[temp.first][temp.second];
        for(int i = 0; i < 4; i++){
            x = temp.first + d[i][0], y =temp.second + d[i][1];

            if(v[x][y] == 0){
                n-=1;
                v[x][y] = time + 1;
                if(time + 1 > m) m = time + 1;
                q.push(make_pair(x, y));
            }
        }
    }
    if(n == 0)printf("%d", m-1);
    else printf("-1");
}