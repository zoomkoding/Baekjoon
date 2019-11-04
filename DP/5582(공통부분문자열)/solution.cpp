#include <iostream>
#include <cstring>
using namespace std;
char p[4001], t[4001];
int pn, tn, dp[4001][4001];
//p는 x에서의 길이 y는 
int find(int x, int y){
    if(x == pn)return 0;
    if(y == tn)return find(x + 1, 0);
    int &ret = dp[x][y];
    if(ret != -1)return ret;
    if(p[x] == t[y])ret = 1 + find(x + 1, y + 1);
    
}

int main(){
    memset(dp, -1, sizeof(dp));
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> p >> t;
    pn = strlen(p), tn = strlen(t);
    cout << find(0, 0);

}