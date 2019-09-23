#include <cstdio>

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        char s1[22], s2[22];
        scanf("%s %s", s1, s2);
        printf("Distances: ");
        for(int i = 0; s1[i] != '\0'; i++){
            printf("%d ", s2[i]-s1[i] >= 0 ? s2[i]-s1[i] : s2[i]-s1[i] + 26);
        }
        printf("\n");
    }
}