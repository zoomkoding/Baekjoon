#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
long long n, cnt, dec[1000001];

void dfs(long long num){
    long long val = num % 10, cur = num * 10;
    for(int i = 0; i < val; i++){
        dec[cnt++] = cur + i;
        dfs(cur + i);
    }
}
int main(){
    scanf("%lld", &n);
    for(int i = 0; i < 10; i++){
        dec[cnt++] = i;
        dfs(i);
    }
    sort(dec, dec+cnt);
    if(n < cnt)printf("%lld", dec[n]);
    else printf("-1");
}