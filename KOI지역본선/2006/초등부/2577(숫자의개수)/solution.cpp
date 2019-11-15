#include <cstdio>
int temp, ans = 1, arr[10];
int main(){
    for(int i = 0; i < 3; i++){
        scanf("%d", &temp);
        ans *= temp;
    }
    while(ans){
        arr[ans % 10]++;
        ans /= 10;
    }
    for(int i = 0; i < 10; i++)printf("%d\n", arr[i]);
}