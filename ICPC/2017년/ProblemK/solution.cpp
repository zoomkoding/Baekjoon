#include <cstdio>

using namespace std;

int a[1001][1001], b[1001][1001];

int main() {
    int n, m, sum = 0;
    scanf(" %d %d", &n, &m);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf(" %d", &a[i][j]);

    for(int i = 0; i < n; i++) {
        int Max = 0;
        int index = -1;
        for(int j = 0; j < m; j++) {
            if(Max < a[i][j]) {
                Max = a[i][j];
                index = j;
            }
        }
        b[i][index] = 1;
    }
    
    for(int j = 0; j < m; j++) {
        int Max = 0;
        int index = -1;
        for(int i = 0; i < n; i++) {
            if(Max < a[i][j]) {
                Max = a[i][j];
                index = i;
            }
        }
        b[index][j] = 1;
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(!b[i][j])
                sum += a[i][j];

    printf("%d", sum);
    
    return 0;
}