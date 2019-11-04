#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

long long t, a, b, n, S;
int main(){
    scanf("%lld", &t);
    while(t--){
        scanf("%lld %lld %lld %lld", &a, &b, &n, &S);
        //n 로 나눈게 현재보다 많으면 a개를 다 써야지
        if(S / n > a)S -= a * n;
        else S -= n * (S / n);
        if(b >= S)printf("YES\n");
        else printf("NO\n");
    }
}