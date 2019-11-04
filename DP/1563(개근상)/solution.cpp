#include <cstdio>
#include <cstring>
int n, dp[1001][2][3];
//x는 날짜, y는 지각, z는 결석이다.
int find(int x, int y, int z){
    if(y == 2 || z == 3)return 0;
    if(x == n)return 1;
    int &ret = dp[x][y][z];
    if(ret != -1)return ret;
    return ret = (find(x + 1, y, 0) + find(x + 1, y + 1, 0) + find(x + 1, y, z + 1)) % 1000000;
}
int main(){
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    printf("%d", find(0, 0, 0));
}