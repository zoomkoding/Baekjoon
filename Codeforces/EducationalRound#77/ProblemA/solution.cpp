#include <cstdio>
long long n, c, sum;
int main(){
    scanf("%lld", &n);
    while(n--){
        scanf("%lld %lld", &c, &sum);
        if(c >= sum)printf("%lld\n", sum);
        else{
            long long x = sum / c, y = sum % c;
            printf("%lld\n", x * x * (c - y) + (x + 1) * (x + 1) * y); 
        }
    }
}