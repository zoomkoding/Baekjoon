#include <cstdio>

int main(){
    int num = 666, cnt = 0, rank = 0, temp, n;
    scanf("%d", &n);
    while(1){
        temp = num, cnt = 0;
        while(temp != 0){
            if(temp % 10 == 6){
                cnt ++;
                if(cnt >= 3){
                    rank++;
                    break;
                }
            }
            else cnt = 0;
            temp /= 10;
        }
        if(rank == n) break;
        num++;
    }
    printf("%d", num);
}