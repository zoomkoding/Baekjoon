#include <iostream>
#include <cstring>
using namespace std;
long long n, p, q, dp[3000000];
long long find(long long i){
    if(i == 0)return 1;
    if(i > 3000000){
        return find(i / p)+find(i / q);
    }
    else{
        long long &ret = dp[i];
        if(ret != -1)return ret;
        return ret = find(i / p) + find(i / q);
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n >> p >> q;
    cout << find(n);
}
