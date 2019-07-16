#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int d[6][3] = {{0,1,0}, {0,-1,0}, {0,0,1}, {0,0,-1}, {1,0,0}, {-1,0,0}};
    int x, y, h, m = 0, n = 0;
    scanf("%d %d %d", &x, &y, &h);
    queue<vector<int> > q;
    vector<vector<vector<int> > > v(h+2);
    for(int k = 0; k < h+2; k++){
        v[k] = vector<vector<int> >(y + 2); 
        for(int i = 0; i < y + 2; i++){
            v[k][i] = vector<int>(x+2);
            for(int j = 0; j < x + 2; j++){
                if(k == 0 || i == 0 || j == 0 || k == h + 1 || i == y + 1 || j == x + 1)v[h][i][j] = -1;
                else{
                    scanf("%d", &v[k][i][j]);
                    vector<int> t(3);
                    t[0] = k, t[1] = i, t[2] = j;
                    if(v[k][i][j] == 1)q.push(t);
                    else if(v[k][i][j] == 0) n++;
                }
            }
        }
    }
    
    if(n == 0){
        printf("0");
        return 0;
    }
    while(!q.empty()){
        vector<int> temp = q.front(); q.pop();
        int time = v[temp[0]][temp[1]][temp[2]];
        for(int i = 0; i < 4; i++){
            h = temp[0] + d[i][0], x =temp[1] + d[i][1], y = temp[2] + d[i][2];

            if(v[h][x][y] == 0){
                n-=1;
                v[h][x][y] = time + 1;
                if(time + 1 > m) m = time + 1;
                vector<int> t(3);
                t[0] = h, t[1] = x, t[2] = y;
                q.push(t);
            }
        }
    }
    if(n == 0)printf("%d", m-1);
    else printf("-1");
}