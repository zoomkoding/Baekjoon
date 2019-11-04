#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int an, bn, cn, dp[101][101][101];
char a[101], b[101], c[101];

int find_cnt(int x, int y, int z){
    if(x == an || y == bn || z == cn)return 0;
    int &ret = dp[x][y][z];
    if(ret != -1)return dp[x][y][z];
    ret = max(max(find_cnt(x + 1, y, z), find_cnt(x, y + 1, z)), find_cnt(x, y, z + 1));
    if(a[x] == b[y] && b[y] == c[z])ret = max(ret, 1 + find_cnt(x + 1, y + 1, z + 1));
    return ret;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> a >> b >> c;
    memset(dp, -1, sizeof(dp));
    an = strlen(a), bn = strlen(b), cn = strlen(c);
    printf("%d", find_cnt(0, 0, 0));
}