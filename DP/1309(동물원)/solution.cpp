#include <cstdio>
int n, arr[100001][2];

int main(){
    arr[1][0] = 1, arr[1][1] = 2;
    scanf("%d", &n);
    for(int i = 2; i <= n; i++){
        arr[i][0] = (arr[i-1][0] + arr[i-1][1]) % 9901;
        arr[i][1] = (arr[i-1][0] * 2 + arr[i-1][1]) % 9901;
    }
    printf("%d", (arr[n][0] + arr[n][1])%9901);
}