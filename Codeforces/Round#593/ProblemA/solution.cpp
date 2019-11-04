#include <cstdio>
#include <algorithm>
using namespace std;
int t, arr[3], temp, temp2;

int main(){
    scanf("%d", &t);
    while(t--){
        int a = 0, b = 0;
        for(int i = 0; i < 3; i++)scanf("%d", &arr[i]);
        temp = min(arr[0], arr[1] / 2);
        a += temp * 3;
        arr[0] -= temp, arr[1] -= temp * 2;
        temp2 = min(arr[1], arr[2] / 2);
        a += temp2 * 3;
        arr[0] += temp, arr[1] += temp * 2;

        temp = min(arr[1], arr[2] / 2);
        b += temp * 3;
        arr[1] -= temp, arr[2] -= temp * 2;
        temp2 = min(arr[0], arr[1] / 2);
        b += temp2 * 3;
        arr[1] += temp, arr[2] += temp * 2;
        printf("%d\n", max(a, b));
    }
}