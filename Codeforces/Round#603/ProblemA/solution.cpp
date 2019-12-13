#include <cstdio>
#include <algorithm>
using namespace std;
long long k, arr[3];
int main(){
    scanf("%lld", &k);
    while(k--){
        scanf("%lld %lld %lld", &arr[0], &arr[1], &arr[2]);
        long long ans = 0;
        sort(arr, arr + 3);
        int dif = arr[2] - arr[1];
        if(dif >= arr[0])ans = arr[0] + arr[1];
        else{
            if((arr[0] - dif) % 2 == 0)ans = arr[0] + arr[1] - (arr[0] - dif) / 2;
            else ans = arr[0] + arr[1] - (arr[0] - dif) / 2 - 1;
        }     
        printf("%lld\n", ans);
    }
}