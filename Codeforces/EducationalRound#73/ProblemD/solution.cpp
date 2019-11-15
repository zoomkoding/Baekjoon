#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
long long t, n, a[300001], b[300001], dp[300001][3];
const long long INF64 = (long long)(1e18) + 100;
//x는 인덱스, y는 추가한 개수
long long find(int x, int y){
    if(x == n + 2)return 0;
    long long &ret = dp[x][y];
    if(ret != -1)return ret;
    //x에서 을 추가해
    for(int i = 0; i < 3; i++){
        //현재 인덱스의 현재 개수에서 다음개수로 보내
        //단 현재 인덱스에서 현재 개수와 다음인덱스의 i개가 같으면 안돼
        if(a[x] + y == a[x + 1] + i)continue;
        ret = min(ret, find(x + 1, i) + b[x + 1] * i);
    }
    return ret;
}

int main(){
    scanf("%lld", &t);
    while(t--){
        scanf("%lld", &n);
        for(int i = 1; i <= n; i++)scanf("%lld %lld", &a[i], &b[i]);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 3; j++)dp[i][j] = -1;
        }
        printf("%lld\n", find(0, 0));
    }

}