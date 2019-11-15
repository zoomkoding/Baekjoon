#include <cstdio>
#include <cstring>
int t, n, temp, arr[200001];
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        memset(arr, -1, sizeof(arr));
        int ans = 987654321;
        for(int i = 0; i < n; i++){
            scanf("%d", &temp);
            if(arr[temp] == -1)arr[temp] = i;
            else {
                if(ans > i - arr[temp] + 1)ans = i - arr[temp] + 1;
                arr[temp] = i;
            }
        }
        if(ans == 987654321)printf("-1\n");
        else printf("%d\n", ans);
    }
}