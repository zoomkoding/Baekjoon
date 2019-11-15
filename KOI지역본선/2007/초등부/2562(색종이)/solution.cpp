#include <cstdio>
int arr[101][101], n, x, y, cnt;
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &x, &y);
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                if(arr[x + j][y + k])cnt--;
                arr[x + j][y + k] = 1;
            }
        }
    }
    printf("%d", n * 100 + cnt);
}