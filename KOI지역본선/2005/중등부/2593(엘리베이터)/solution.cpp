#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, X[101], Y[101], A, B, dp[100001], visited[10001], pre_e[100001], pre_f[100001];
int find(int x){
    printf("%d\n", x);
    if(x == B)return 0;
    int &ret = dp[x];
    if(ret != -1)return ret;
    int temp = 987654321;
    for(int i = 0; i < m; i++){
        if(x - X[i] < 0)continue;
        if((x - X[i]) % Y[i] != 0)continue;
        if(visited[i])continue;
        visited[i] = 1;
        for(int j = X[i]; j <= n; j+= Y[i]){
            int next = find(j) + 1;
            if(temp > next)temp = next, pre_e[x] = i + 1, pre_f[x] = j;
        }
        visited[i] = 0;
    }
    return ret = temp;
}

void find_pre(int x){
    if(x == B)return;
    printf("%d\n", pre_e[x]);
    find_pre(pre_f[x]);
}

int main(){
    memset(dp, -1, sizeof(dp));
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++)scanf("%d %d", &X[i], &Y[i]);
    scanf("%d %d", &A, &B);
    int ans = find(A);
    if(ans == 987654321)printf("-1");
    else {
        printf("%d\n", ans);
        find_pre(A);
    }

}