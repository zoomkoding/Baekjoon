#include <cstdio>
int n, s, m, v[102], arr[102][1001];
int main(){
    scanf("%d %d %d", &n, &s, &m);
    arr[0][s] = 1;
    for(int i = 1; i <= n; i++)scanf("%d", &v[i]);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(!arr[i-1][j]) continue;
            int v1 = j - v[i], v2 = j + v[i];
            if(v1 >= 0)arr[i][v1] = 1;
            if(v2 <= m)arr[i][v2] = 1;
        }
    }
    for(int i = m; i >= 0; i--){
        if(arr[n][i]){
            printf("%d", i);
            return 0;
        }
    }
    printf("-1");
}