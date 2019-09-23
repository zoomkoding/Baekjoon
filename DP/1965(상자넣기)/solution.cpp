#include <cstdio>
int ans, n, input[1001], arr[1001];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)scanf("%d",& input[i]);
    arr[1] = 1;
    for(int i = 2; i <= n; i++){
        int temp = input[i], MAX = 0;
        for(int j = 1; j < i; j++){
            if(temp > input[j] && arr[j] > MAX)MAX = arr[j];
        }
        arr[i] = MAX + 1;
        if(arr[i] > ans) ans = arr[i];
    }
    printf("%d", ans);
}