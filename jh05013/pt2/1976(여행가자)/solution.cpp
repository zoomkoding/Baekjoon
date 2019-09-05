#include <cstdio>

int main(){
    int n, m, arr[201][201];
    scanf("%d %d", &n, &m);
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < n + 1; j++)scanf("%d", &arr[i][j]);
        arr[i][i] = 1;
    }
    for(int k = 1; k < n + 1; k++){
        for(int i = 1; i < n + 1; i++){
            for(int j = 1; j < n + 1; j++){
                if(arr[i][k] && arr[k][j])arr[i][j] = 1;
            }
        }
    }
    int v1, v2;
    int ans = 1;
    scanf("%d", &v1);
    for(int i = 0; i < m - 1; i++){
        scanf("%d", &v2);
        if(!arr[v1][v2] && !arr[v2][v1])ans = 0;
        v1 = v2;
    }
    if(ans)printf("YES");
    else printf("NO");
}