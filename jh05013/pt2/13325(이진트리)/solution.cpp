#include <iostream>

using namespace std;

int k, n, m, sum, w[2 << 21], MAX[2 << 21];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> k;
    n = (2 << k) - 2;
    m = (2 << (k - 1)) - 2;
    for(int i = 1; i <= n; i++){
        cin >> w[i];
        sum += w[i];
    }
    for(int i = n; i >= 0; i--) MAX[i] = w[i] + max(MAX[i*2 + 1], MAX[i*2 + 2]);
    for(int i = 0; i <= m; i++) sum += (MAX[i] - w[i]) * 2 - MAX[i * 2 + 1] - MAX[i * 2 + 2];
    cout << sum;
}