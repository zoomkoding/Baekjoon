#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m, k, v1, v2, w, arr[301][301], dp[301][301];
//x는 현위치, y는 횟수
int find(int x, int y){
    if(x == n)return 0;
    if(y >= m)return -987654321;
    int &ret = dp[x][y];
    if(ret != -1)return ret;
    for(int i = x + 1; i <= n; i++){
        if(!arr[x][i])continue;
        ret = max(ret, arr[x][i] + find(i, y + 1));
    }
    return ret;
}
int main(){
    memset(dp, -1, sizeof(dp));
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < k; i++){
        scanf("%d %d %d", &v1, &v2, &w);
        arr[v1][v2] = max(arr[v1][v2], w);
    }
    printf("%d", find(1, 1));   
}