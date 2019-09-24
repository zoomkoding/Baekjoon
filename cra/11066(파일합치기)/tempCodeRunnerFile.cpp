#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t, n;
    cin >> t;
    while(t--){
        int cost[501][501] = {0,}, sum[501] = {0,};
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> sum[i];
            sum[i] += sum[i - 1];
        }
        for(int k = 1; k < n; k++){
            for(int i = 0; i < n - k; i++){
                for(int j = i; j < i + k; j++){
                    if(!cost[i][i+k] || cost[i][j] + cost[j+1][i+k] + sum[i+k+1] - sum[i] < cost[i][i+k])cost[i][i+k] = cost[i][j] + cost[j+1][i+k] + sum[i+k+1] - sum[i];
                }
            }
        }
        printf("%d\n", cost[0][n-1]);
    }
}
