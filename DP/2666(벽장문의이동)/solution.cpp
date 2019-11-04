#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace  std;
int n, m, sx, sy, door[21], dp[21][21][21];
int find(int i, int x, int y){
    if(i == m) return 0;
    int &ret = dp[i][x][y];
    if(ret != -1)return dp[i][x][y];
    ret = min(abs(door[i] - x) + find(i + 1, door[i], y), abs(door[i] - y) + find(i + 1, x, door[i]));
    return ret;
}
int main(){
    memset(dp, -1, sizeof(dp));
    scanf("%d %d %d %d", &n, &sx, &sy, &m);
    for(int i = 0; i < m; i++)scanf("%d", &door[i]);
    printf("%d", find(0, sx, sy));
}