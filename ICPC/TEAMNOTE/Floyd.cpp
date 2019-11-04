#include <cstdio>
#include <vector>

using namespace std;

int n, m, x, w, v1, v2, M, d[1001][1001];

int main(){
    scanf("%d %d %d", &n, &m, &x);
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < n + 1; j++)d[i][j] = 1000000;
        d[i][i] = 0;
    }
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &v1, &v2, &w);
        d[v1][v2] = w;
    }
    for(int k = 1; k < n + 1; k++){
        for(int i = 1; i < n + 1; i++){
            for(int j = 1; j < n + 1; j++){
                if(d[i][j] > d[i][k] + d[k][j])d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
    for(int i = 1; i < n + 1; i++){
        if(M < d[i][x] + d[x][i])M = d[i][x] + d[x][i];
    }
    printf("%d", M);
}