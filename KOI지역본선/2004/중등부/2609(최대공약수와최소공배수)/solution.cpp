#include <cstdio>
long long n1, n2;
int main(){
    scanf("%lld %lld", &n1, &n2);
    for(long long i = n1; i > 0; i--){
        if(n1 % i == 0 && n2 % i == 0){
            printf("%lld\n", i);
            break;
        }
    }
    for(long long i = n1; ; i += n1){
        if(i % n2 == 0){
            printf("%lld", i);
            break;
        }
    }

}