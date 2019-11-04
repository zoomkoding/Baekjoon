#include <cstdio>
int n, c0, c1, n0, n1;
int main(){
    c1 = 2;
    scanf("%d", &n);
    for(int i = 1; i < n; i++)n1 = (c0 * 2) % 16769023, n0 = c1, c0 = n0, c1 = n1;
    printf("%d", (c0 + c1) % 16769023);
}