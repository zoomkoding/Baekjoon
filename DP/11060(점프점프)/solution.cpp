#include <cstdio>
int n, arr[1001], A[1001];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
        arr[i] = 2000;
    }
    arr[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= A[i]; j++){
            if(arr[i + j] > arr[i] + 1)arr[i + j] = arr[i] + 1;
        }
    }
    if(arr[n - 1] == 2000) printf("-1");
    else printf("%d", arr[n - 1]);
}