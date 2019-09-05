#include <cstdio>
int cnt[16], n;
int main(){
    cnt[0] = 1, cnt[1] = 3;
    scanf("%d", &n);
    if(n%2){
        printf("0");
        return 0;
    }
    n /= 2;
    for(int i = 2; i <= n; i++){
        cnt[i] = cnt[i-1]*3;
        for(int j = 2; i >= j; j++)cnt[i]+= cnt[i-j]*2;
    }
    printf("%d", cnt[n]);
}