#include <cstdio>
int n, m, x, ans, arr[1001][1001];
int d[3][2] = { {0, -1}, {-1, -1}, {-1, 0} };
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)scanf("%1d", &arr[i][j]);
    }
    ans = arr[0][0];
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(!arr[i][j])continue;
            int min = 987654321;
            for(int k = 0; k < 3; k++)if(min > arr[i + d[k][0]][j + d[k][1]])min = arr[i + d[k][0]][j + d[k][1]];
            arr[i][j] = min + 1;
            if(min + 1 > ans) ans = min + 1;
        }
    }
    printf("%d", ans*ans);
}