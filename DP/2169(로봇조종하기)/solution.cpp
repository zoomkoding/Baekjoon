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

int n, m, arr[1001][1001], dp[1001][1001];

int main(){
    n = fio::readInt(); m = fio::readInt();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            arr[i][j] = fio::readInt();
            dp[i][j] = -987654321;
        }
    }
    dp[0][0] = arr[0][0];
    for(int i = 1; i < m; i++)dp[0][i] = dp[0][i - 1] + arr[0][i];
    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            int sum = dp[i - 1][j];
            for(int k = j; k < m; k++){
                sum += arr[i][k];
                if(dp[i][k] < sum)dp[i][k] = sum;
            }
            sum = dp[i - 1][j];
            for(int k = j; k >= 0; k--){
                sum += arr[i][k];
                if(dp[i][k] < sum)dp[i][k] = sum;
            }
        }
    }
    printf("%d", dp[n - 1][m - 1]);
}