#include <cstdio>
#include <algorithm>

int n, m[100001][3], M[100001][3];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < 3; i++){
        scanf("%d", &m[0][i]);
        M[0][i] = m[0][i];
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &m[i][j]);
            M[i][j] = m[i][j];
            if(j == 0) M[i][j] += max(M[i-1][0], M[i-1][1]), m[i][j] += min(m[i-1][0], m[i-1][1]);
            else if(j == 1) M[i][j] += max(max(M[i-1][0], M[i-1][1]), M[i-1][2]), m[i][j] += min(min(m[i-1][0], m[i-1][1]), m[i-1][2]);
            else M[i][j] += max(M[i-1][1], M[i-1][2]), m[i][j] += min(m[i-1][1], m[i-1][2]);
        }
    }
    printf("%d %d", max(max(M[n - 1][0], M[n - 1][1]), M[n - 1][2]), min(min(m[n - 1][0], m[n - 1][1]), m[n - 1][2])); 
}
