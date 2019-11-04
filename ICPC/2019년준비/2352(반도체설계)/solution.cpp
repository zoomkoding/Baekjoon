#include <cstdio>
#include <vector>
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

int n, arr[40001], cnt;
vector<int> ans;
int main(){
    n = fio::readInt();
    for(int i = 0; i < n; i++)arr[i] = fio::readInt();
    for(int i = 0; i < n; i++){
        if(!cnt || ans[cnt - 1] < arr[i])ans.push_back(arr[i]), cnt++;
        else{
            int pos = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
            ans[pos] = arr[i];
        }
    }
    printf("%d", cnt);
}