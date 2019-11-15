#include <cstdio>
int temp, M, M_i;
int main(){
    for(int i = 1; i <= 9; i++){
        scanf("%d", &temp);
        if(temp > M)M = temp, M_i = i;
    }
    printf("%d\n%d", M, M_i);
}