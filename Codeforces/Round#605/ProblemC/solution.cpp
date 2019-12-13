#include <cstdio>
long long arr[26], n, m, ans, cons;
char temp, s[1000001];

int main(){
    scanf("%lld %lld", &n, &m);
    scanf("%s", s);
    for(int i = 0; i < m; i++){
        scanf(" %c", &temp);
        arr[temp - 'a'] = 1;
    }
    for(int i = 0; i < n; i++){
        if(arr[s[i] - 'a'] == 1){
            cons++;
            continue;
        }
        ans += (cons*(cons+1))/2;
        cons = 0;
    }
    ans += (cons*(cons+1))/2;
    printf("%lld", ans);
}