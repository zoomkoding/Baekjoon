#include <cstdio>

int n, a[1001], sum[1001], MAX;
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)scanf("%d", &a[i]);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(a[i] <= a[j])continue;
            if(sum[i] < sum[j])sum[i] = sum[j];
        }
        sum[i] += a[i];
        if(sum[i] > MAX) MAX = sum[i];
    }
    printf("%d", MAX);
}