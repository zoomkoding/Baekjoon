#include <cstdio>
#include <algorithm>
using namespace std;

int t, r, b, k;
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &r, &b, &k);
        if(r > b)swap(r, b);
        int c = __gcd(r, b);
        if(r == b)printf("OBEY\n");
        else if(((b - c - 1) / r) >= k - 1)printf("REBEL\n");
        else printf("OBEY\n");
    }
}