#include <cstdio>
long long m, n, min, sum, arr[10001];
int main(){
    arr[1] = 1;
    for(int i = 2; i < 10001; i++){
        if(arr[i])continue;
        for(int j = i + i; j < 10001; j+= i)arr[j] = 1;
    }
    scanf("%lld %lld", &m, &n);
    for(int i = n; i >= m; i--){
        if(arr[i])continue;
        min = i, sum += i;
    }
    if(sum)printf("%lld\n%lld", sum, min);
    else printf("-1");
}