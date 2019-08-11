#include <cstdio>
int n, arr[1001], m[1001], cnt = 0, ans = 0;
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        for(int j = cnt; j >= 0; j--){
            if(m[j] < arr[i]){
                if(j == cnt)cnt ++;
                m[j + 1] = arr[i];
                break;
            }
        }
    }
    printf("%d", cnt);
}

//이 문제는 각 수열 레벨의 min값을 저장함므로써 해결할 수 있는 문제이다.