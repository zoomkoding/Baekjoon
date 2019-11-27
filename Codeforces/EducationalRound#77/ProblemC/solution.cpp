#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int gcd_modulus(int u, int v){
    int t;
    while (v){
        t = u%v;
        u = v;
        v = t;
    }
    return u;
}

long long t, r, b, k;
int main(){
    scanf("%lld", &t);
    while(t--){
        scanf("%lld %lld %lld", &r, &b, &k);
        if(r > b)swap(r, b);
        int c = gcd_modulus(r, b);
        if(r == b)printf("OBEY\n");
        else if(b % r == 0){
            if(k > b / r - 1)printf("OBEY\n");
            else printf("REBEL\n");
        }
        else{
            if(((b - c - 1) / r) >= k - 1)printf("REBEL\n");
            else printf("OBEY\n");
        }
        
    }
}