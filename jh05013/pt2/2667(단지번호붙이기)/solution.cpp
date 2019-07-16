#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int> > v;
queue<pair<int, int> > q;
int d[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

int bfs(int x, int y){
    int c = 1;
    v[x][y] = 0;
    q.push(make_pair(x, y));
    while(!q.empty()){
        pair<int, int> temp = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int X = temp.first + d[i][0], Y = temp.second + d[i][1];
            if(v[X][Y]){
                v[X][Y] = 0;
                q.push(make_pair(X, Y));
                c ++;
            }
        }
    }
    return c;
}

int main(){
    int n;
    scanf("%d ", &n);
    vector<int> answer;
    v = vector<vector<int> >(n + 2);
    for(int i = 0; i < n + 2; i++){
        v[i] = vector<int>(n + 2);
        if(i == 0 || i == n + 1) continue;
        for(int j = 1; j < n + 1; j++){
            char temp;
            scanf("%c", &temp);
            v[i][j]= temp - '0';
        }
        getchar();
    }
    for(int i = 1; i < n + 2; i++){
        for(int j = 1; j < n + 2; j++){
            if(v[i][j])answer.push_back(bfs(i, j));
        }
    }
    sort(answer.begin(), answer.end());
    printf("%lu\n", answer.size());
    for(int i = 0; i < answer.size(); i++)printf("%d\n", answer[i]);
}
