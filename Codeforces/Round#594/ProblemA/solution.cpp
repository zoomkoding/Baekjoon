#include <cstdio>
int t, n, m;
//s1 짝수, s2 홀수
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        long long p = 0, s1 = 0, s2 = 0, q = 0, ans = 0;
        for(int i = 0; i < n; i++){
            scanf("%lld", &p);
            if(p % 2 == 0)s1++;
            else s2++;
        }
        scanf("%d", &m);
        for(int i = 0; i < m; i++){
            scanf("%lld", &q);
            if(q % 2 == 0)ans += s1;
            else ans += s2;
        }
        printf("%lld\n", ans);
    }
}