#include <cstdio>
int q, n, p[202];
int main(){
    scanf("%d", &q);
    while(q--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)scanf("%d", &p[i]);
        for(int i = 1; i <= n; i++){
            int temp = i, cnt = 0;
            while(p[temp] != i)temp = p[temp], cnt++;
            printf("%d ", cnt + 1);
        }
        printf("\n");
    }
}