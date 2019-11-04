#include <cstdio>
int n, arr[2001], ans[2001][2001], m, v1, v2;
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)scanf("%d", &arr[i]);
    for(int i = 0; i < n; i++){
        for(int j = 0; i - j >= 0 && i + j < n; j++){
            if(arr[i - j] != arr[i + j])break;
            ans[i - j][i + j] = 1;
        }
        for(int j = 0; i - j >= 0 && i + 1 + j < n; j++){
            if(arr[i - j] != arr[i + 1 + j])break;
            ans[i - j][i + 1 + j] = 1;
        }
    }
    scanf("%d", &m);
    while(m--){
        scanf("%d %d", &v1, &v2);
        printf("%d\n", ans[v1 - 1][v2 - 1]);
    }
}