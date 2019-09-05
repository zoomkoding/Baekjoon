#include <cstdio>
int n, k, c[1001][1001];
int main(){
    scanf("%d %d", &n, &k);
    c[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= k; j++){
            if(j-1 < 0)c[i][j] = c[i-1][j];
            c[i][j] = (c[i-1][j] + c[i-1][j-1])%10007;
        }
    }
    printf("%d", c[n][k]);
}