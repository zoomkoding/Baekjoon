#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, A[2001], B[2001], dp[2001][2001];
int find(int x, int y){
    if(x == n || y == n)return 0;
    int &ret = dp[x][y];
    if(ret != -1) return ret;
    ret = max(find(x + 1, y + 1), find(x + 1, y));
    if(A[x] > B[y])ret = max(ret, find(x, y + 1) + B[y]);
    return ret;
}
int main(){
    scanf("%d", &n);
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++)scanf("%d", &A[i]);
    for(int i = 0; i < n; i++)scanf("%d", &B[i]);
    printf("%d", find(0, 0));
}