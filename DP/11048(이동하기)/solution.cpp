#include <cstdio>
int n, m, arr[1001][1001], result[1001][1001];
int d[4][2] = { {1, 0}, {0, 1}, {1, 1} };
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)scanf("%d", &arr[i][j]);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < 3; k++){
                int nx = i + d[k][0], ny = j + d[k][1];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
                if(result[nx][ny] < result[i][j] + arr[i][j]) result[nx][ny] = result[i][j] + arr[i][j];
            }
        }
    }
    printf("%d", result[n-1][m-1] + arr[n-1][m-1]);
}