#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m, p, dp[21][301], arr[21][301], pre[21][301];
//x기업을 투자할 차례에 y만큼에 돈이 있다면
int find(int x, int y){
    if(x == m || y == 0)return 0;
    int &ret = dp[x][y];
    if(ret != -1)return ret;
    for(int i = 0; i <= y; i++){
        int next = arr[x][i] + find(x + 1, y - i);
        if(next > ret)ret = next, pre[x][y] = i;
    }
    return ret;
}

void print(int x, int y){
    if(x == m)return;
    printf("%d ", pre[x][y]);
    print(x + 1, y - pre[x][y]);
}

int main(){
    memset(dp, -1, sizeof(dp));
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &p);
        for(int j = 0; j < m; j++)scanf("%d", &arr[j][p]);
    }
    printf("%d\n", find(0, n));
    print(0, n);
}