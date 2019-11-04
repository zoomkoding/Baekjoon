#include <cstdio>
int main(){
    long long x, y, z, ans = -1;
    scanf("%lld %lld", &x, &y);
    z = y*100 / x + 1;
    if(z == 100 || z == 101){
        printf("-1");
        return 0;
    }
    long long l = 1, r = 1000000000;
    while(l <= r){
        long long mid = (l + r) / 2;
        long long val = (y + mid)*100 / (x + mid);
        //현재는 될 수 있는 값 중에 가장 작은 값을 찾는 중
        if(z <= val) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    printf("%lld", ans);
}


