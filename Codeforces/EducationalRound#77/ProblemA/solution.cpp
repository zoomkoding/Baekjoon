#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
using namespace std;
long long n, c, sum;
int main(){
    scanf("%lld", &n);
    while(n--){
        scanf("%lld %lld", &c, &sum);
        if(c >= sum)printf("%lld\n", sum);
        else{
            long long basic = sum / c, rest = sum % c;
            printf("%lld\n", basic*basic*(c - rest) + (basic+1)*(basic+1)*rest); 
        }
    }
}