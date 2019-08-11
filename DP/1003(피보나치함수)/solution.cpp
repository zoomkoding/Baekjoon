#include <cstdio>
int zero[41], one[41], n, k;

int main(){
    zero[0] = 1;
    one[1] = 1;
    for(int i = 2; i <= 40; i++){
        zero[i] = zero[i - 1] + zero[i - 2];
        one[i] = one[i - 1] + one[i - 2];
    }
    scanf("%d", &n);
    while(n--){
        scanf("%d", &k);
        printf("%d %d\n", zero[k], one[k]);
    }
}