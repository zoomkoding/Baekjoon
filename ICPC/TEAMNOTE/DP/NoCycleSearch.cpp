//사이클 없을 때 DP를 이용해서 빠르게 탐색 가능
//1937번 욕심쟁이 판다 1949번 우수마을

#include <cstdio>
#include <vector>
using namespace std;
int n, v1, v2, ans, dp[10002][2], w[10002], visited[10002];
vector<vector<int> > e;

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

int main(){
    scanf("%d", &n);
    e = vector<vector<int> >(n + 1);
    for(int i = 1; i <= n; i++)scanf("%d", &w[i]);
    for(int i = 0; i < n - 1; i++){
        scanf("%d %d", &v1, &v2);
        e[v1].push_back(v2);
        e[v2].push_back(v1);
    }
    visited[1] = 1;
    find(1);
    ans = max(dp[1][0], dp[1][1]);
    printf("%d", ans);
}