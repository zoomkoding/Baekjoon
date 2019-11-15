#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
using namespace std;
int q, h, n, arr[200001], dp[2000001];

int find(int x){
    if(x == n - 1)return 0;
    int &ret = dp[x];
    if(ret != -1)return ret;
    ret = 987654321;
    if(arr[x] == 3){
        if(arr[x + 1] == 2)ret = 1;
        else ret = 0;
    }
    if(arr[x] == 2)ret = 0;
    if(x != n - 2 && arr[x + 1] == arr[x + 2] + 1)ret = min(ret, find(x + 2));  
    ret = min(ret, 1 + find(x + 1));
    return ret;
}

int main(){
    scanf("%d", &q);
    while(q--){
        memset(dp, -1, sizeof(dp));
        scanf("%d %d", &h, &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        printf("%d\n", find(0));
    }
}