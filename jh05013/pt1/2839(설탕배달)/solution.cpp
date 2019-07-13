#include <cstdio>

int sum, num, left;
int main(){
    scanf("%d", &num);
    sum = num / 5;
    left = num % 5;
    while(left <= num){
        if(left % 3 == 0){
            sum += left / 3;
            break;   
        }
        sum --;
        left += 5; 
    }
    if(left > num)printf("-1");
    else printf("%d", sum);
}