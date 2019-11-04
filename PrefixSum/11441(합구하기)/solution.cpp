#include <cstdio>

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
int n, m, A[100001], v1, v2;

int main(){
    n = fio::readInt();
    for(int i = 1; i <= n; i++)A[i] = fio::readInt();
    for(int i = 2; i <= n; i++)A[i] += A[i - 1];
    m = fio::readInt();
    while(m--){
        v1 = fio::readInt(), v2 = fio::readInt();
        printf("%d\n", A[v2] - A[v1 - 1]);
    }   
}