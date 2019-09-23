#include <cstdio>
#include <string.h>

int main(){
    char s[101][15];
    int n, sn[101];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", s[i]);
        int cn = strlen(s[i]);
        sn[i] = cn;
        for(int j = 0; j <= i; j++){
            if(sn[j] != cn)continue;
            int good = 1;
            for(int k = 0; k < cn/2; k++){
                if(s[i][k] != s[j][cn - 1 - k]){
                    good = 0;
                    break;
                }
            }
            if(good){
                printf("%d %c", cn, s[i][cn/2]);
                return 0;
            }
        }
    }
}