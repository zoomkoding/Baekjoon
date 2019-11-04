#include <cstdio>
long long ans, n, num[101], arr[101][21];
int main(){
    scanf("%lld", &n);
    for(int i = 0; i < n - 1; i++)scanf("%lld", &num[i]);
    scanf("%lld", &ans);
    arr[0][num[0]] = 1;
    for(int i = 1; i < n - 1; i++){
        int cur = num[i];
        for(int j = 0; j < 21; j++){
            if(!arr[i-1][j])continue;
            int add = j + cur, sub = j - cur;
            if(add <= 20)arr[i][add] += arr[i-1][j];
            if(sub >= 0)arr[i][sub] += arr[i-1][j];
        }
    }
    printf("%lld", arr[n - 2][ans]);
}