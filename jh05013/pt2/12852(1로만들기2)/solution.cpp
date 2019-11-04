#include <cstdio>
#include <algorithm>
using namespace std;
int x, arr[3000001], p[3000001];

int main(){
    scanf("%d", &x);
    for(int i = 2; i <= x; i++)arr[i] = i;
    for(int i = 1; i <= x; i++){
        int v = arr[i] + 1;
        if(arr[i * 3] > v)arr[i * 3] = v, p[i * 3] = i;
        if(arr[i * 2] > v)arr[i * 2] = v, p[i * 2] = i;
        if(arr[i + 1] > v)arr[i + 1] = v, p[i + 1] = i;
    }
    printf("%d\n", arr[x]);
    while(x != 0){
        printf("%d ", x);
        x = p[x];
    }
}