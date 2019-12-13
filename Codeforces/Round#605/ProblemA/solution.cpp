#include <cstdio>
#include <algorithm>
using namespace std;
long long n, arr[3];
int main(){
    scanf("%lld", &n);
    while(n--){
        scanf("%lld %lld %lld", &arr[0], &arr[1], &arr[2]);
        sort(arr, arr+3);
        long long d1 = arr[1] - arr[0], d2 = arr[2] - arr[1];
        if(d1 == 0 && d2 == 0){
            printf("0\n");
            continue;
        }
        if(d1 == 0){
            d2 -= 2;
            if(d2 < 0)d2 = 0;
        }
        else if(d2 == 0){
            d1 -= 2;
            if(d1 < 0) d1 = 0;
        }
        else d1 --, d2 --;
        printf("%lld\n", (d1 + d2) * 2);
    }
}