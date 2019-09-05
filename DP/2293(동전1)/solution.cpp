#include <cstdio>

int n, m, unit[101], arr[100001];

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)scanf("%d", &unit[i]);
    for(int i = 0; i < n; i++){
        arr[unit[i]] += 1;
        for(int j = 1; j <= m; j++){
            if(j - unit[i] >= 0)arr[j] += arr[j - unit[i]];
        }
    }
    printf("%d", arr[m]);
}