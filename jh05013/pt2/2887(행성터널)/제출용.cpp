
//풀이는 아래 블로그를 참고해주세요!
//zoomkoding.github.io/codingtest/2019/09/27/baekjoon-2887.html

#include <cstdio>
#include <queue>
#include <cmath>
#include <algorithm>
#define pii pair<int, int>
#define pip pair<int, pii>
#define x first
#define y second
#define N 100002
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

int vs, cnt, n, par[N];
pii X[N], Y[N], Z[N];
int find(int i){
    if(par[i] == i)return i;
    return par[i] = find(par[i]);
}
int main(){
    long long ans = 0;
    n = readInt();
    for(int i = 0; i < n; i++){
        X[i].y = Y[i].y = Z[i].y = i + 1;
        X[i].x = readInt(), Y[i].x = readInt(), Z[i].x = readInt();
        par[i] = i;
    }
    sort(X, X+n), sort(Y, Y+n), sort(Z, Z+n);
    vector<pip> v(n*3);
    int j = 0;
    for(int i = 1; i < n; i++){
        v[j++] = pip(abs(X[i].x - X[i-1].x), pii(X[i].y, X[i-1].y));
        v[j++] = pip(abs(Y[i].x - Y[i-1].x), pii(Y[i].y, Y[i-1].y));
        v[j++] = pip(abs(Z[i].x - Z[i-1].x), pii(Z[i].y, Z[i-1].y));
    }
    sort(v.begin(), v.end());
    vs = v.size();
    for(int i = 0; i < vs; i++){
        int px = find(v[i].y.x), py = find(v[i].y.y);      
        if(px == py)continue;
        ans += v[i].x, cnt++, par[px] = py;
        if(cnt == n - 1)break;
    }
    printf("%lld", ans);
}