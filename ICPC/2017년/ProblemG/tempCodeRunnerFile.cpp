#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define pll pair<long long, long long>
long long n, ans = 100000;
pll arr[10001], cnt[10001];
int main(){
    scanf("%d", &n);
    for(long long i = 0; i < n; i++)scanf("%d", &arr[i].first);
    for(long long i = 0; i < n; i++)scanf("%d", &arr[i].second);
    sort(arr, arr+n);
    for(long long k = 0; k < n; k++){
        long long cnt = k, cur = arr[k].first;
        for(long long i = k + 1; i < n; i++){
            long long x = arr[i].first, y = arr[i].second;
            if(cur > x)cnt++;
            //들어갈 수 있다면
            if(x >= cur + y) cur = x; 
            else cur += y;
        }
        if(ans > cnt)ans = cnt;
    }
    printf("%d", ans);
}