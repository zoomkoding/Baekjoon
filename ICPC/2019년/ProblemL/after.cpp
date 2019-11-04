#include <cstdio>
int n, arr[251][2], ans = 987654321;

void dfs(int v1, int v2, int i){
    if(i == n){
        int v = v1 > v2 ? v1 : v2;
        if(v < ans)ans = v;
        return;
    }
    dfs(v1 + arr[i][0], v2, i + 1);
    dfs(v1, v2 + arr[i][1], i + 1);
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)scanf("%d %d", &arr[i][0], &arr[i][1]);
    dfs(0, 0, 0);
    printf("%d", ans);
}