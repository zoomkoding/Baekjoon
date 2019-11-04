#include <cstdio>
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

int ans, n, m, a, b, arr[501][501]; 
int main(){
    n = fio::readInt(); m = fio::readInt();
    for(int i = 0; i < m; i++){
        a = fio::readInt(); b = fio::readInt();
        arr[a][b] = 1;
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(arr[i][k] + arr[k][j] == 2)arr[i][j] = 1;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        int valid = 1;
        for(int j = 1; j <= n; j++){
            if(i == j)continue;
            if(arr[i][j] + arr[j][i] == 0){
                valid = 0; break;
            }
        }
        if(valid)ans++;
    }
    printf("%d", ans);
}