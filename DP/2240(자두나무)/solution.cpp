#include <cstdio>
#include <algorithm>
using namespace std;
int ans, t, w, n, arr[1001][31];
int main(){
    scanf("%d %d %d", &t, &w, &n);
    if(n == 1)arr[0][0] = 1;
    else arr[0][1] = 1;
    for(int i = 1; i < t; i++){
        scanf("%d", &n);
        arr[i][0] = arr[i - 1][0];
        if(n == 1)arr[i][0]++;
        for(int j = 1; j <= w; j++){
            arr[i][j] = max(arr[i - 1][j], arr[i - 1][j - 1]);
            if(j % 2 == n - 1)arr[i][j]++;
        }
    }
    for(int i = 0; i <= w; i++){
        if(ans < arr[t - 1][i])ans = arr[t - 1][i];
    }
    printf("%d", ans);
}