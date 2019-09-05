#include <cstdio>

int n, m, arr[100001], num[100001];

int main(){
    scanf("%d", &n);
    for(int i = 1; i < 100001; i++){
        int sqr = i*i;
        if(sqr > n)break;
        num[i] = sqr, m = i + 1;
    }
    for(int i = 1; i <= n; i++){
        int MIN = 1000000;
        for(int j = 0; j < m; j++){
            if(i - num[j] < 0) continue;
            if((i - num[j]) && !arr[i - num[j]])continue;
            if(arr[i - num[j]] + 1 < MIN) MIN = arr[i - num[j]] + 1;
        }
        arr[i] = MIN;
    }
    printf("%d", arr[n]);
}