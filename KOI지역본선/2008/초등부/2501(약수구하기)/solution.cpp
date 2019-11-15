#include <cstdio>
int n, m, cnt, ans;
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            cnt++;
            if(cnt == m){
                ans = i;
                break;
            }
        }        
    }
    printf("%d", ans);
}