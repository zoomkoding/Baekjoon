#include <cstdio>

int n, m, n1, n2, **d, min = 0;
int main(){
    scanf("%d %d", &n, &m);
    d = new int*[n+1];
    for(int i = 0; i < n+1; i++){
        d[i] = new int[n+1];
        for(int j = 1; j < n+1; j++)d[i][j] = 5000;
    }
    for(int i = 0; i < m; i++){
        scanf("%d %d", &n1, &n2);
        d[n1][n2] = d[n2][n1] = 1;
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n ; i++){
            for(int j = 1; j <= n; j++){
                if(d[i][j] > d[i][k] + d[k][j])d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
    for(int i = 1; i < n+1; i++){
        d[i][0] = 0;
        for(int j = 1; j < n+1; j++)d[i][0] += d[i][j];
        if(d[i][0] < d[min][0])min = i;
    }
    printf("%d", min);
}