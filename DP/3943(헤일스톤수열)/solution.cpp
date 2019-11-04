#include <cstdio>
#include <algorithm>
using namespace std;
int dp[1000001], t, n;
int find(int x){
    if(x == 1)return 1;
    if(x > 100000){
        if(x % 2) return max(x, find(x * 3 + 1));
        else return max(x, find(x / 2));
    }
    else{
        int &ret = dp[x];
        if(ret)return ret;
        if(x % 2) return ret = max(x, find(x * 3 + 1));
        else return ret = max(x, find(x / 2));

    }
    
}
int main(){
    dp[1] = 1;
    for(int i = 100000; i > 1; i--){
        if(!dp[i])dp[i] = find(i);
    }
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }


}