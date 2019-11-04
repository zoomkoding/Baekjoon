#include <cstdio>
int cnt, sum, temp, arr[101];
int main(){
    for(int i = 0; i < 5; i++){
        scanf("%d", &temp);
        sum += temp;
        arr[temp]++;
    }
    for(int i = 10; i < 101; i+= 10){
        if(arr[i])cnt += arr[i];
        if(cnt >= 3){
            printf("%d\n%d", sum / 5, i);
            break;
        }
    }
}