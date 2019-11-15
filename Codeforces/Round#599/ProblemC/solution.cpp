#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
long long n, m, val, cnt;
//sqrt(n)보다 작은 약수를 구하고 이를 이용해서 
int main(){
    scanf("%lld", &n);
    m = sqrt(n);
    for(long long i = 2; i <= m; i++){
        if(n % i == 0){
            if(val == 0)val = i, cnt++;
            if(i % val != 0)cnt++;
            long long next = n / i;
            if(next % val != 0)cnt++;
        }
    }
    if(cnt == 1)printf("%lld", val);
    else if(cnt >= 2)printf("1");
    else printf("%lld", n);
}