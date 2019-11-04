#include <iostream>
#include <algorithm>
using namespace std;
int n, arr[5001], dp[5001][5001], ans = 987654321;
int pa(int x, int y){
    if(x == -1)return n - y;
    if(y == n) return x + 1;
    int &ret = dp[x][y];
    if(ret != -1)return ret;
    if(arr[x] == arr[y]) return ret = pa(x - 1, y + 1);
    else return ret = 1 + min(pa(x - 1, y), pa(x, y + 1));
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++)dp[i][j] = -1;
    }
    for(int i = 0; i < n; i++)cin >> arr[i];
    for(int i = 1; i < n; i++)ans = min(ans, min(pa(i, i), pa(i - 1, i))); 
    cout << ans;
}