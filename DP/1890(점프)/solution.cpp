#include <cstdio>

long long arr[101][101], ans[101][101];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)scanf("%lld", &arr[i][j]);
    }
    ans[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == n - 1 && j == n - 1)break;
            if(i + arr[i][j] < n)ans[i + arr[i][j]][j] += ans[i][j];
            if(j + arr[i][j] < n)ans[i][j + arr[i][j]] += ans[i][j];
        }
    }
    printf("%lld", ans[n-1][n-1]);
}