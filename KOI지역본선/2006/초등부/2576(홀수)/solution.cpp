#include <cstdio>
int temp, sum, min = 987654321;
int main(){
    for(int i = 0; i < 7; i++){
        scanf("%d", &temp);
        if(temp % 2){
            sum += temp;
            if(temp < min)min = temp;
        }
    }
    if(!sum)printf("-1");
    else printf("%d\n%d", sum, min);
}