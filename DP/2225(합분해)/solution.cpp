#include <cstdio>
int n, k, arr[201][201];
int main(){
    scanf("%d %d", &n, &k);
    for(int i = 0; i <= n; i++)arr[1][i] = 1;
    for(int i = 2; i <= k; i++){
        for(int j = 0; j <= n; j++){
            for(int k = 0; k <= n; k++){
                if(j - k < 0)continue;
                arr[i][j] = (arr[i][j] + arr[i - 1][j-k]) % 1000000000; 
            }
        }
    }
    printf("%d", arr[k][n]);
}