#include <cstdio>
int n, m, x[2][301], cnt[2];
int main(){
    scanf("%d %d", &n, &m);
    x[0][n] = 1, x[1][m] = 1;
    for(int i = 0; i < 2; i++){
        for(int j = 300; j > 1; j--){
            if(!x[i][j])continue;
            x[i][j/2] += x[i][j], x[i][j - j/2]+= x[i][j];
            cnt[i]+= x[i][j];
        }
    }
    int nfirst = cnt[0] + cnt[1]*n, mfirst = cnt[1] + cnt[0]*m;
    printf("%d", mfirst > nfirst ? nfirst : mfirst); 
}

//가로를 한개까지 자르는 횟수(cnt[0])를 구한 값에 가로 갯수(n)에 세로 자르는 횟수(cnt[1])를 더해준다.
//양방향으로 진행한 뒤 더 작은 거를 선택한다.