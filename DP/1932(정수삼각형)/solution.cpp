#include <cstdio>
int sum[501][501], tree[501][501];
int main(){
    int n, M = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            scanf("%d", &tree[i][j]);
        }
    }
    sum[0][0] = tree[0][0];
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j <= i; j++){
            if(sum[i+1][j] < sum[i][j] + tree[i+1][j])sum[i+1][j] = sum[i][j] + tree[i+1][j];
            if(sum[i+1][j+1] < sum[i][j] + tree[i+1][j+1])sum[i+1][j+1] = sum[i][j] + tree[i+1][j+1];
        }
    }
    for(int i = 0; i < n; i++){
        if(sum[n-1][i] > M) M = sum[n-1][i];
    }
    printf("%d", M);

}