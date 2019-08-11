#include <cstdio>

int n, arr[1001];

int main(){
    scanf("%d", &n);
    arr[1] = 1, arr[2] = 2;
    for(int i = 3; i <= n; i++)arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
    printf("%d", arr[n]);
}
