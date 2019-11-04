#include <cstdio>
int n, cnt, ans, sum, temp, arr[1001];
int main(){
    for(int i = 0; i < 10; i++){
        scanf("%d", &temp);
        sum += temp;
        arr[temp]++;
    }
    for(int i = 10; i < 1001; i+= 10){
        if(cnt < arr[i])cnt = arr[i], ans = i;
    }
    printf("%d\n%d", sum / 10, ans);
}