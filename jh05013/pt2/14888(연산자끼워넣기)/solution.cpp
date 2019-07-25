#include <cstdio>
int n, o[4], arr[10], M = -1000000000, m = 1000000000;

void find(int cnt, int r){
    if(cnt == n){
        if(r > M) M = r;
        if(r < m) m = r;
        return;
    }
    for(int i = 0; i < 4; i++){
        if(o[i]){
            o[i]--;
            if(i == 0)find(cnt+1, r+arr[cnt]);
            else if(i == 1)find(cnt+1, r-arr[cnt]);
            else if(i == 2)find(cnt+1, r*arr[cnt]);
            else find(cnt+1, r/arr[cnt]);
            o[i]++;
        }
    }
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)scanf("%d", &arr[i]);
    for(int i = 0; i < 4; i++)scanf("%d", &o[i]);
    find(1, arr[0]);
    printf("%d\n%d", M, m);
}
