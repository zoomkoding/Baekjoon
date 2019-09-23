#include <cstdio>

int main(){
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int cnt = 0;
        int arr[101] = {0,};
        for(int i = 1; i <= n; i++){
            for(int j = i; j <= n; j+= i)arr[j] = !arr[j];
        }
        for(int i = 1; i <= n; i++)if(arr[i])cnt++;
        printf("%d\n", cnt);
    }
}