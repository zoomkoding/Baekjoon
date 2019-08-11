#include <cstdio>

int t, n, sum[11];

int main(){
    sum[1] = 1, sum[2] = 2, sum[3] = 4;
    for(int i = 4; i < 11; i++)sum[i] = sum[i - 1] + sum[i - 2] + sum[i - 3];
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("%d\n", sum[n]);
    }
}
