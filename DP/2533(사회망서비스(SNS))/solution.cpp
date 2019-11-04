#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
namespace fio {
	const int BS = 524288;
	char buf[BS];
	char *p = buf + BS;
	inline char readChar() {
		if (p == buf + BS) {
			fread(buf, 1, BS, stdin);
			p = buf;
		}
		return *p++;
	}
	int readInt() {
		char c = readChar();
		while (c < '0') c = readChar();
		int ret = 0;
		while (c >= '0')ret = ret * 10 + c - '0', c = readChar();
		return ret;
	}
}
vector<int> v[1000001];
int n, p, q, dp[1000001][2];
int find(int par, int root, int flag){
    int nochild = 1, o = 0, x = 1;
    int &ret = dp[root][flag];
    if(ret != -1)return dp[root][flag];
    for(int i = 0; i < v[root].size(); i++){
        if(par == v[root][i])continue;
        nochild = 0;
        if(flag){
            o += find(root, v[root][i], 0);
            x += find(root, v[root][i], 1);
        }
        else {
            x += find(root, v[root][i], 1);
        } 
    }
    if(nochild)return ret = !flag;
    if(flag)return ret = min(o, x);
    else return ret = x;
}
int main(){
    memset(dp, -1, sizeof(dp));
    n = fio::readInt();
    for(int i = 0; i < n - 1; i++){
        p = fio::readInt(), q = fio::readInt();
        v[p].push_back(q);
        v[q].push_back(p);
    }
    printf("%d", find(0, 1, 1));
}