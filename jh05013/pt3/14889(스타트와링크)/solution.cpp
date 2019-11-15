#include <cstdio>
#include <algorithm>
using namespace std;
int n, arr[21][21], X[21], ans = 987654321;

void find(int x, int y, int z){
    if(z == n / 2){
        int pt2 = 0;
        for(int i = 1; i <= n; i++){
            if(X[i] == 1)continue;
            for(int j = i + 1; j <= n; j++){
                if(X[j] == 1)continue;
                pt2 += arr[i][j] + arr[j][i];
            }
        }
        if(abs(y - pt2) < ans) ans = abs(y - pt2);
    }
    for(int i = x + 1; i <= n; i++){
        int temp = y;
        for(int j = 1; j <= n; j++){
            if(X[j] == 1)temp += arr[i][j] + arr[j][i];
        }
        X[i] = 1;
        find(i, temp, z + 1);
        X[i] = 0;
    }
    
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)scanf("%d", &arr[i][j]);
    }
    find(0, 0, 0);
    printf("%d", ans);
}