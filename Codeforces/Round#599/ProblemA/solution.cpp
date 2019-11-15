#include <cstdio>
int t, n, arr[1001];
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++)scanf("%d", &arr[i]);
        for(int i = n; i >= 1; i--){
            int sum = 0;
            for(int j = 0; j < n; j++){
                if(arr[j] >= i)sum++;
            }
            if(sum >= i){
                printf("%d\n", i);
                break;
            }
        }
    }
}