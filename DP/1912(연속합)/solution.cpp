#include <cstdio>

int main(){
    int arr[100001], n, ans = -987654321;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int m = 0;
    if(arr[0] > ans) ans = arr[0]; 
    for(int i = 1; i < n; i++){
        arr[i] += arr[i-1];
        if(arr[i] - arr[m] > ans)ans = arr[i] - arr[m];
        if(arr[i] > ans)ans = arr[i];
        if(arr[m] > arr[i])m = i;
    }
    
    printf("%d", ans);
}