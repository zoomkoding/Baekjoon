#include <cstdio>

int n, arr[1001], ans[1001][2];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        int MAX = 0;
        for(int j = 0; j < i; j++){
            if(arr[i] <= arr[j])continue;
            if(ans[j][0] > MAX)MAX = ans[j][0];
        }
        ans[i][0] = MAX + 1;
    }
    for(int i = n - 1; i >= 0; i--){
        int MAX = 0;
        for(int j = n - 1; j > i; j--){
            if(arr[i] <= arr[j])continue;
            if(ans[j][1] > MAX)MAX = ans[j][1];
        }
        ans[i][1] = MAX + 1; 
    }
    int answer = 0;
    for(int i = 0; i < n; i++){
        if(ans[i][0] + ans[i][1] > answer) answer = ans[i][0] + ans[i][1];
    }
    printf("%d", answer - 1);
    
}