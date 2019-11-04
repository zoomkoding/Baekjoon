//풀이는 아래 블로그를 참고해주세요!
//zoomkoding.github.io/codingtest/2019/09/26/baekjoon-13306.html

#include <cstdio>
#include <vector>

using namespace std;

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

int n, ans_n, q, x, a, b, c, d, par[200001];

int find(int i){
    if(par[i] == i)return i;
    return par[i] = find(par[i]);
}

int main(){
    int temp[200001], data[400002][2];
    n = readInt(), q = readInt();
    vector<int> ans(q);
    par[1] = 1, temp[1] = 1;
    for(int i = 2; i <= n; i++){
        temp[i] = readInt();
        par[i] = i;
    }
    for(int i = 0; i < n + q - 1; i++){
        x = readInt();
        if(x) data[i][0] = readInt(), data[i][1] = readInt();
        else data[i][0] = readInt();
    }
    for(int i = n + q - 2; i >= 0; i--){
        if(data[i][1]) ans[ans_n++] = find(data[i][0]) == find(data[i][1]);
        else par[data[i][0]] = temp[data[i][0]];
    }
    for(int i = ans.size() - 1; i >= 0; i--)printf("%s\n", ans[i] ? "YES" : "NO");
}