#include <cstdio>
#include <algorithm>
using namespace std;
int n, temp, t, h, arr[10001], dp[3001][3001];
void find(int x){
    dp[0][x] = arr[x] * t;
    
}

int main(){
    for(int i = 0; i < 3001; i++){
        for(int j = 0; j < 3001; j++)dp[i][j] = 987654321;
    }
    scanf("%d", &n);
    for(int i = 0; i < n; i++)scanf("%d", &arr[i]);
    scanf("%d %d", &t, &h);
    sort(arr, arr + n);
    
}