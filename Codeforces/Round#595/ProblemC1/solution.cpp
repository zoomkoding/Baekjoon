#include <cstdio>
int n, q, arr[20001];
int main(){
    arr[0] = 1;
    for(int i = 1; i < 20001; i *= 3){
        for(int j = 20000; j - i >= 0; j--){
            if(arr[j - i])arr[j] = 1;
        }
    }
    scanf("%d", &q);
    while(q--){
        scanf("%d", &n);
        for(int i = n; i < 20001; i++){
            if(arr[i]){
                printf("%d\n", i);
                break;
            }
        }
    }
}