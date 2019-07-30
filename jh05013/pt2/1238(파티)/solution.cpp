#include <cstdio>

using namespace std;

int n, m, x, w, v1, v2, M, d[1001][1001];

char buf[1 << 17];

inline char read() {
	static int idx = 1 << 17;
	if (idx == 1 << 17) {
		fread(buf, 1, 1 << 17, stdin);
		idx = 0;
	}
	return buf[idx++];
}
inline int readInt() {
	int sum = 0;
	bool flg = 1;
	char now = read();

	while (now == 10 || now == 32) now = read();
	if (now == '-') flg = 0, now = read();
	while (now >= 48 && now <= 57) {
		sum = sum * 10 + now - 48;
		now = read();
	}

	return flg ? sum : -sum;
}

int main(){
    n = readInt(), m = readInt(), x = readInt();
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < n + 1; j++)d[i][j] = 1000000;
        d[i][i] = 0;
    }
    for(int i = 0; i < m; i++){
        v1 = readInt(), v2 = readInt(), w = readInt();
        d[v1][v2] = w;
    }
    for(int k = 1; k < n + 1; k++){
        for(int i = 1; i < n + 1; i++){
            for(int j = 1; j < n + 1; j++){
                if(d[i][j] > d[i][k] + d[k][j])d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
    for(int i = 1; i < n + 1; i++){
        if(M < d[i][x] + d[x][i])M = d[i][x] + d[x][i];
    }
    printf("%d", M);
}