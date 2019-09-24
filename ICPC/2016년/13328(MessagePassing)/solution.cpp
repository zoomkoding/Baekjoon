#include <cstdio>
#include <queue>

using namespace std;

long long n, m, d[51];

int main(){
    scanf("%lld %lld", &n, &m);
    long long cnt = 0;
    d[0] = 1;
    while(m--){
        cnt = 0;
        for(int i = n - 1; i >= 0; i--){
            d[i+1] = d[i];
            cnt += d[i];
        }
        d[0] = cnt;
    }
    printf("%lld", cnt % 320000);
}