#include <cstdio>
int n, w, arr[500001]; 

int main(){
    int MAX = 0, MIN = 1000000000;
    scanf("%d %d", &w, &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        if(arr[i] > MAX)MAX = arr[i];
    }
    int l = MAX, r = 1000000000, ans = 0;
    while(l <= r){
        int mid = (l + r) / 2, t = 0;
        printf("%d", mid);
        int sum = arr[0], m = w + 1;
        for(int i = 1; i < n; i++){
            if(sum + arr[i] <= mid) sum += arr[i];
            else t++, sum = arr[i];
            
        }
        t++;
        
        if(mid <= t){
            r = mid -1;
        }
        else {
            ans = mid;
            l = mid + 1;
        }
    }
    printf("%d\n", ans);
    printf("%d", (w - ans)*(w-ans));
}