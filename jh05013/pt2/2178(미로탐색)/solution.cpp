#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int> > v;
queue<pair<int, int> > q;
int d[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

int main(){
    int n, m;
    scanf("%d %d ", &n, &m);
    vector<int> answer;
    v = vector<vector<int> >(n + 2);
    for(int i = 0; i < n + 2; i++){
        v[i] = vector<int>(m + 2);
        if(i == 0 || i == n + 1) continue;
        for(int j = 1; j < m + 1; j++){
            char temp;
            scanf("%c", &temp);
            v[i][j]= temp - '0';
        }
        getchar();
    }

    q.push(make_pair(1, 1));
    while(!q.empty()){
        pair<int, int> temp = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int t = v[temp.first][temp.second];
            int X = temp.first + d[i][0], Y = temp.second + d[i][1];
            if(v[X][Y] == 1){
                if(X == 1 && Y == 1)continue;
                v[X][Y] = t + 1;
                q.push(make_pair(X, Y));
            }
        }
    }
    printf("%d", v[n][m]);

}
