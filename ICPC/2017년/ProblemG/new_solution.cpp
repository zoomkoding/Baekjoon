#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define pii pair<int, int>
int n, ans = 100000;
pii arr[10001], cnt[10001];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)scanf("%d", &arr[i].first);
    for(int i = 0; i < n; i++)scanf("%d", &arr[i].second);
    sort(arr, arr+n);
    for(int k = 0; k < n; k++){
        int cnt = k, cur = arr[k].first;
        for(int i = k + 1; i < n; i++){
            int x = arr[i].first, y = arr[i].second;
            if(cur > x)cnt++;
            //들어갈 수 있다면
            if(x >= cur + y) cur = x; 
            else cur += y;
        }
        if(ans > cnt)ans = cnt;
    }
    printf("%d", ans);
}