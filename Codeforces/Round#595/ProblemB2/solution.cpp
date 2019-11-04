#include <cstdio>
int q, n, p[200001], par[200001], v[200001];

int main(){
    scanf("%d", &q);
    while(q--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &p[i]);
            par[i] = i;
        }
        for(int i = 1; i <= n; i++){
            if(par[i] != i){
                v[i] = v[par[i]];
                continue;
            }
            int temp = i, cnt = 1;
            while(p[temp] != i)temp = p[temp], cnt++, par[temp] = i;
            v[i] = cnt;
        }
        for(int i = 1; i <= n; i++)printf("%d ", v[i]);
        
        printf("\n");
    }
}