#include <cstdio>
int N, n, m, k;
unsigned long long nCr[201][201];
int main(){
    scanf("%d %d %d", &n, &m, &k);
    N = n + m;
    nCr[1][0] = 1;    
    nCr[1][1] = 1;
    for (int i = 2; i <= 200; i++){
        nCr[i][0] = 1;
        for (int j = 1; j <= 200; j++){
            nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];
         }
    }
    if(nCr[N][n] < k){
        printf("-1");
        return 0;
    }

    for(int i = 0; i < N - 1; i++){
        //a를 선택했을 때의 경우의 수
        if(!n){
            printf("z");
            m--;
            continue;
        }
        unsigned long long x = nCr[n + m - 1][n - 1];
        if(k > x){
            printf("z");
            k -= x, m --;
        }
        else {
            printf("a");
            n --;
        }
    }
    if(n)printf("a");
    else printf("z");
}