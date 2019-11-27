#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
using namespace std;
long long t, a, b, x;
int main(){
    scanf("%lld", &t);
    while(t--){
        scanf("%lld %lld", &a, &b);
        if(a < b)swap(a, b);
        if(a > b * 2)printf("NO\n");
        else{
            if((2 * b - a) % 3 == 0)printf("YES\n");
            else printf("NO\n");
        }
    }
}