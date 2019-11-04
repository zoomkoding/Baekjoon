#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, ddr[100001], dp[100001][5][5];
int find(int i, int x, int y){
    if(i == n)return 0;
    int &ret = dp[i][x][y], v1, v2;
    if(ret != -1)return ret;
    //x가 움직인 경우 
    if(x == 0) v1 = 2;
    else if(x == 2 && ddr[i] == 4) v1 = 4;
    else if(x == 4 && ddr[i] == 2) v1 = 4;
    else if(x == 1 && ddr[i] == 3) v1 = 4;
    else if(x == 3 && ddr[i] == 1) v1 = 4;
    else v1 = 3;
    if(y == 0) v2 = 2;
    else if(y == 2 && ddr[i] == 4) v2 = 4;
    else if(y == 4 && ddr[i] == 2) v2 = 4;
    else if(y == 1 && ddr[i] == 3) v2 = 4;
    else if(y == 3 && ddr[i] == 1) v2 = 4;
    else v2 = 3;

    if(ddr[i] == x || ddr[i] == y)ret = 1 + find(i + 1, x, y);
    else ret = min(v1 + find(i + 1, ddr[i], y), v2 + find(i + 1, x, ddr[i]));
    return ret;
}
int main(){
    memset(dp, -1, sizeof(dp));
    while(1){
        scanf("%d", &ddr[n]);
        if(ddr[n] == 0)break;
        n++;
    }
    printf("%d", find(0, 0, 0));
}