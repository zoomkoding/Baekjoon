#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int ans, n; 
int main(){
    scanf("%d", &n);
    vector<int> arr(n);
    for(int i = 0 ; i < n; i++)scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end());
    int l = 0, r = arr[n-1];
    while(l <= r){
        int k = ( l + r ) / 2;
        int up = n - (lower_bound(arr.begin(), arr.end(), k) - arr.begin());
        if(up < k) r = k - 1;
        //k보다 같거나 많으면 끝까지 가서 제일 큰 애를 발견해내야해
        else ans = k, l = k + 1;
    }
    printf("%d", ans);
}