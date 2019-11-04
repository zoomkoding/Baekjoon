#include <cstdio>

int n, m, arr[100001], num[100001];

int main(){
    scanf("%d", &n);
    for(int i = 1; i < 100001; i++){
        //일단 해당 수 전의 모든 제곱수들을 다 저장해줌
        int sqr = i*i;
        if(sqr > n)break;
        num[i] = sqr, m = i + 1;
    } 
    for(int i = 1; i <= n; i++){
        int MIN = 1000000;
        //i에서 제곱수들을 뺀 위치에 값이 있는 애들 중에 제일 작은 값 + 1을 넣어줌
        for(int j = 0; j < m; j++){
            if(i - num[j] < 0) continue;
            if((i - num[j]) && !arr[i - num[j]])continue;
            if(arr[i - num[j]] + 1 < MIN) MIN = arr[i - num[j]] + 1;
        }
        arr[i] = MIN;
    }
    printf("%d", arr[n]);
}