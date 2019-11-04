#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[10001][101];
int b[3001][101];

int main(){
    int n, l, m, w;
    scanf(" %d %d %d %d", &n, &l, &m, &w);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf(" %d", &a[i][j]);

    for(int i = 0; i < l; i++)
        for(int j = 0; j < m; j++)
            scanf(" %d", &b[i][j]);
    
    

    return 0;
}