#include <cstdio>
int arr[1001][10], ans, n;
int main(){
    scanf("%d", &n);
    for(int i = 0; i < 10; i++)arr[1][i] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < 10; j++){
            for(int k = j; k < 10; k++){
                arr[i][k] = (arr[i][k] + arr[i-1][j])%10007;
            }
        }
    }
    for(int i = 0; i < 10; i++)ans = (ans + arr[n][i])%10007;
    printf("%d", ans);
}