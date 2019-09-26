#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int ans, n, v1, v2, w[10002], dp[10002][2], visited[10002];
vector<vector<int> > e; 
vector<int> answer;

void find(int x){
    for(int i = 0; i < e[x].size(); i++){
        int nx = e[x][i];
        if(visited[nx])continue;
        visited[nx] = 1;
        find(nx);
        dp[x][0] += dp[nx][1];
        dp[x][1] += max(dp[nx][0], dp[nx][1]);
    }
    dp[x][0] += w[x];
}

void get_ans(int x, int print){
    if(print && dp[x][0] > dp[x][1]){
        answer.push_back(x);
        print = 0;
    }
    else print = 1;
    for(int i = 0; i < e[x].size(); i++){
        int nx = e[x][i];
        if(visited[nx])continue;
        visited[nx] = 1;
        get_ans(nx, print);
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i < n + 1; i++)scanf("%d", &w[i]);
    e = vector<vector<int> >(n + 1); 

    for(int i = 0; i < n - 1; i++){
        scanf("%d %d", &v1, &v2);
        e[v1].push_back(v2);
        e[v2].push_back(v1);
    }
    visited[1] = 1;
    find(1);
    for(int i = 2; i < n + 1; i++)visited[i] = 0;
    get_ans(1, 1);
    sort(answer.begin(), answer.end());
    printf("%d\n", max(dp[1][0], dp[1][1]));
    for(int i = 0; i < answer.size(); i++)printf("%d ", answer[i]);
}