#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
long long n, temp, q, three[50], n1;
int main(){
    //3으로 만들 수 있는 총 가지수를 만들어
    for(long long i = 1; i < 1350851717672992090; i *= 3)three[n1++] = i;
    scanf("%lld", &q);
    while(q--){
        scanf("%lld", &n);
        int arr[50] = {0,}, n2 = 0, pos2 = -1, pos0 = -1;
        temp = n;
        //3진수 만들기
        while(temp)arr[n2++] = temp % 3, temp /= 3;
        //pos2 찾기
        for(int i = n2 - 1; i >= 0; i--){
            if(arr[i] == 2){
                pos2 = i;
                break;
            }
        }
        //이미 good이면 출력
        if(pos2 == -1){
            printf("%lld\n", n);
            continue;
        }
        //pos0 찾기
        for(int i = pos2 + 1; i < 50; i++){
            if(arr[i] == 0){
                pos0 = i, n += three[pos0];
                break;
            }
        }
        //pos0 아래 값들 다 빼주기
        for(int i = 0; i < pos0; i++)n -= three[i] * arr[i];
        printf("%lld\n", n);
    }
}