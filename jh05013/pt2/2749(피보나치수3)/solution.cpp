#include <cstdio>

int mem[1500000];
int main(){
    long long n;
    scanf("%lld", &n);
    mem[0] = 0, mem[1] = 1;
    for(int i = 2; i < 1500000; i++)mem[i] = (mem[i-1] + mem[i-2])%1000000;
    
    printf("%d", mem[n%1500000]);
}