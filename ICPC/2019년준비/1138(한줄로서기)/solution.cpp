#include <cstdio>
int n, arr[11], visited[11];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)scanf("%d", &arr[i]);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[j] || visited[j])continue;
            printf("%d ", j + 1);
            visited[j] = 1;
            for(int k = 0; k < j; k++)arr[k]--;
            break;
        }
    }
    
}