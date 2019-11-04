#include <cstdio>
int n, m, p, k[101];
int main(){ 
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &p);
        int M = -1, M_i = -1;
        for(int j = 0; j < m; j++){
            //현재 k번쨰 위치가 p보다 커
            if(k[j] > p)continue;
            if(k[j] > M)M = k[j] , M_i = j;
        }
        if(M_i == -1){
            printf("NO");
            return 0;
        }
        k[M_i] = p;
    }
    printf("YES");
}