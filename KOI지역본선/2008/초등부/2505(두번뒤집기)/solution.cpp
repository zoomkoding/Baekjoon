#include <cstdio>
#include <algorithm>
using namespace std;
int n, arr[10001];
void SWAP(int x, int y){
    if(x == y || x > y)return;
    swap(arr[x], arr[y]);
    SWAP(x + 1, y - 1);
}
int find(int x, int cnt){
    if(x == n + 1)return;
    if(x == arr[x])return find(x + 1, cnt);
    for(int i = x + 1; i <= n; i++){
        if(arr[i] != x) continue;
        SWAP(x, i);
        find(x + 1, cnt + 1);
        SWAP(x, i);
    }
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)scanf("%d", &arr[i]);

}