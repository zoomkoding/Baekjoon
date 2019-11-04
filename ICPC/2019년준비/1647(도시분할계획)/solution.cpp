#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
#define pii pair<int, int>
#define pip pair<int, pii>
int ans, cnt, n, m, a, b, c, par[100001];

namespace fio {
	const int BSIZE = 524288;
	char buffer[BSIZE];
	char *p = buffer + BSIZE;
	inline char readChar() {
		if (p == buffer + BSIZE) {
			fread(buffer, 1, BSIZE, stdin);
			p = buffer;
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

int find(int i){
    if(par[i] == i)return i;
    return par[i] = find(par[i]);
}

int main(){
    n = fio::readInt(); m = fio::readInt();
    for(int i = 1; i <= n; i++)par[i] = i;
    priority_queue<pip> pq;
    for(int i = 0; i < m; i++){
        a = fio::readInt(); b = fio::readInt(); c = fio::readInt();
        pq.push(pip(-c, pii(a, b)));
    }
    while(!pq.empty() && cnt != n - 2){
        pip top = pq.top(); pq.pop();
        int tv = top.first, tx = top.second.first, ty = top.second.second;
        int px = find(tx), py = find(ty);
        if(px == py)continue;
        ans += -tv, cnt++;
        par[px] = py;
    }
    printf("%d", ans);
}