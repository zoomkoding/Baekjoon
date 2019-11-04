#include <cstdio>
int x, y, n, m, k, arr[16][16];
int main(){
    scanf("%d %d %d", &n, &m, &k);     
    arr[0][0] = 1; 
    x = (k - 1) / m, y = (k - 1) - x * m;
    if(k != 0){
        for(int i = 0; i <= x; i++){
            for(int j = 0; j <= y; j++){
                if(i + 1 <= x)arr[i + 1][j] += arr[i][j];
                if(j + 1 <= y)arr[i][j + 1] += arr[i][j];
            }
        }
    }
    else x = 0, y = 0;
    for(int i = x; i < n; i++){
        for(int j = y; j < m; j++){
            if(i + 1 < n)arr[i + 1][j] += arr[i][j];
            if(j + 1 < m)arr[i][j + 1] += arr[i][j];
        }
    }
    printf("%d", arr[n - 1][m - 1]);
}