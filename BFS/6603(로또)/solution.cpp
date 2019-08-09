#include <cstdio>
int v[6], arr[50], k;
void dfs(int begin, int cnt){
    if(cnt == 6){
        for(int i = 0; i < 6; i++)printf("%d ", v[i]);
        printf("\n");
        return;
    }
    for(int i = begin; i < k; i++){
        v[cnt] = arr[i];
        dfs(i + 1, cnt + 1);
    }
}

int main(){
    while(1){
        scanf("%d", &k);
        if(k == 0)break;
        for(int i = 0; i < k; i++)scanf("%d", &arr[i]);
        dfs(0, 0);
        printf("\n");
    }
    
}