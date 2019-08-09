#include <cstdio>

int main(){
    int a, b, v;
    scanf("%d %d %d", &a, &b, &v);
    int d = a - b, l = 1, r = v, ans = 1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(v <= (long long)((mid - 1) * d + a)) r = mid - 1;    
        else l = mid + 1, ans = mid + 1;
    }
    printf("%d", ans);
}