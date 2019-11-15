#include <cstdio>
int n, s, arr[21], ans;
void find(int x, int sum){
    if(x != 0 && sum == s)ans ++;
    if(x == n)return;
    for(int i = x + 1; i <= n; i++)find(i, sum + arr[i]);
}

int main(){
    scanf("%d %d", &n, &s);
    for(int i = 1; i <= n; i++)scanf("%d", &arr[i]);
    find(0, 0);
    printf("%d", ans);
}