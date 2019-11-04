#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define pii pair<int, int>
int n, cnt, cur = -10000000;
pii arr[10001];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)scanf("%d", &arr[i].first);
    for(int i = 0; i < n; i++)scanf("%d", &arr[i].second);
    sort(arr, arr+n);
    for(int i = 0; i < n; i++){
        int x = arr[i].first, y = arr[i].second;
        if(cur > x)cnt++;
        //들어갈 수 있다면
        if(x - y >= cur) cur = x; 
        else cur += y;
    }
    printf("%d", n - cnt);
}