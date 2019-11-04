#include <cstdio>
long long t, x, arr[68];
int main(){
    arr[0] = arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for(int i = 4; i < 69; i++)arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3] + arr[i - 4];
    scanf("%lld", &t);
    while(t--){
        scanf("%lld", &x);
        printf("%lld\n", arr[x]);
    }
}