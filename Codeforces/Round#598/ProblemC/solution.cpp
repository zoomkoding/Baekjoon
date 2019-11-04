#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int n, m, d, arr[1001], sum;
//x위치에서 y번째 보드를 기다리는 중
int find(int x, int y, int z){
    if(x + d + arr[y] - 1 < n - z + arr[y])
    return find(x + d + arr[y] - 1, y + 1, z - arr[y]);
    else 
    return find(n - z +)
    
}
int main(){
    scanf("%d %d %d", &n, &m, &d);
    for(int i = 0; i < m; i++){
        scanf("%d", &arr[i]);
    }
    printf("%s", find(0, 0) ? "YES" : "NO");
    
}