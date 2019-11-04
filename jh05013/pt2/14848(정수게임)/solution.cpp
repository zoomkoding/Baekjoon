#include <cstdio>
int n, k, arr[16], cnt;
int main(){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < k; i++){
        scanf("%d", &arr[i]);
        int check = 1;
        for(int j = 0; j < i; j++){
            if(arr[i]%arr[j] == 0){
                check = 0;
                break;
            }
        }
        if(check)cnt += n / arr[i];
    }
    printf("%d", n - cnt);
}