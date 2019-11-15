#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int q, n, r;
int arr[100001];
int main(){
    scanf("%d", &q);
    while(q--){
        int m = 0;
        scanf("%d %d", &n, &r);
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        int ans = 0;
        sort(arr, arr + n, greater<int>());
        n = unique(arr, arr + n) - arr;
        for(int i = 0; i < n; i++){
            if(arr[i] - ans * r > 0)ans++;
            else break;
        }
        printf("%d\n", ans);
        
    }
}