#include <cstdio>
int n, m;
long long A[1000001];
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)scanf("%lld", &A[i]);
    for(int i = 2; i <= n; i++)A[i] += A[i - 1];
    //큰 덩어리가 m으로 나눠 떨어지면 그중에 또 나눠떨어지는게 내부에 존재한다.

}

