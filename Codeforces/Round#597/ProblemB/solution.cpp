#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int t, dp[101][101][101], ans[101][101][101], n, arr[3];
char s[101];

int find(int r, int c, int p, int t){
    if(t == n)return 0;
    int &ret = dp[r][c][p];
    if(ret != -1)return ret;
    int t1 = -1, t2 = -1, t3 = -1;
    if(r != 0)t1 = find(r - 1, c, p, t + 1);
    if(c != 0)t2 = find(r, c - 1, p, t + 1);
    if(p != 0)t3 = find(r, c, p - 1, t + 1);

    if(s[t] == 'R' && t3 != - 1)t3++;
    else if(s[t] == 'S' && t1 != - 1)t1++;
    else if(s[t] == 'P' && t2 != - 1)t2++;
    if(t1 >= t2 && t1 >= t3)ans[r][c][p] = 0;
    else if(t2 >= t1 && t2 >= t3)ans[r][c][p] = 1;
    else if(t3 >= t1 && t3 >= t2)ans[r][c][p] = 2;
    return ret = max(t1, max(t2, t3));
}

void check(int x, int y, int z, int t){
    if(t == n)return;
    int &ret = ans[x][y][z];
    if(ret == 0){
        printf("R");
        check(x - 1, y, z, t + 1);
    }
    else if(ret == 1){
        printf("S");
        check(x, y - 1, z, t + 1);
    }
    else if(ret == 2){
        printf("P");
        check(x, y, z - 1, t + 1);
    }
}

int main(){
    scanf("%d", &t);
    while(t--){
        memset(dp, -1, sizeof(dp));
        memset(ans, -1, sizeof(ans));
        scanf("%d %d %d %d %s", &n, &arr[0], &arr[2], &arr[1], s);
        int cnt = find(arr[0], arr[1], arr[2], 0);
        int x = n % 2 ? n / 2 + 1 : n / 2;
        if(cnt >= x){
            printf("YES\n");
            check(arr[0], arr[1], arr[2], 0);
            printf("\n");
        }
        else printf("NO\n");

    }
}
