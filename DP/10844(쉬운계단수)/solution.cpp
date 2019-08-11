#include <cstdio>

long long n, num[101][10];
int main(){
    for(int i = 1; i < 10; i++)num[1][i] = 1;
    scanf("%lld", &n);    
    for(int i = 1; i < n; i++){
        num[i+1][0] = num[i][1] % 1000000000;
        for(int j = 1; j < 9; j++) num[i+1][j] = (num[i][j-1] + num[i][j+1]) % 1000000000;
        num[i+1][9] = num[i][8] % 1000000000;
    }
    long long ans = 0;
    for(int i = 0; i < 10; i++) ans = (ans + num[n][i]) % 1000000000; 
    printf("%lld", ans);
}