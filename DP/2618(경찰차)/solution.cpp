#include <cstdio>
#include <cstring>
#include <algorithm>
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

int n, dp[1001][1001], pre[1001][1001], w, x[1001], y[1001];
int find_cnt(int i, int p, int q){
    int px, py, qx, qy;
    if(i == w + 1)return 0;
    int &ret = dp[p][q];
    if(ret != -1)return ret;
    if(!p)px = 1, py = 1;
    else px = x[p], py = y[p];
    if(!q)qx = n, qy = n;
    else qx = x[q], qy = y[q];
    int first = find_cnt(i + 1, i, q) + abs(px - x[i]) + abs(py - y[i]);
    int second = find_cnt(i + 1, p, i) + abs(qx - x[i]) + abs(qy - y[i]);
    if(first < second)ret = first, pre[p][q] = 1;
    else ret = second, pre[p][q] = 2;
    return ret;
}

void find_pre(int i, int p, int q){
    if(i == w + 1)return;
    printf("%d\n", pre[p][q]);
    if(pre[p][q] == 2)find_pre(i + 1, p, i);
    else if(pre[p][q] == 1)find_pre(i + 1, i, q);
}
int main(){
    n = fio::readInt(), w = fio::readInt();
    memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= w; i++)x[i] = fio::readInt(), y[i] = fio::readInt();
    printf("%d\n", find_cnt(1, 0, 0));
    find_pre(1, 0, 0);
}