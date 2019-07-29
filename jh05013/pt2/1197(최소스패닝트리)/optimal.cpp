#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define X first
#define Y second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using T = pair<int, pii>;

int pa[10000];

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

int fnd(int n) {
	if (!pa[n]) return n;
	return pa[n] = fnd(pa[n]);
}

void uni(int a, int b) {
	a = fnd(a);
	b = fnd(b);
	pa[b] = a;
}

int main() {
	int v = readInt(), e = readInt();

	int a, b, c;
	vector<T> edge;
	for (int i = 0; i < e; ++i) {
        a = readInt();
        b = readInt();
        c = readInt();
		edge.push_back({ c, { a, b } });
	}

	sort(edge.begin(), edge.end());

	int ans = 0;
	for (T &it : edge) {
		if (fnd(it.Y.X) == fnd(it.Y.Y)) continue;
		ans += it.X;
		uni(it.Y.X, it.Y.Y);
	}

	printf("%d", ans);

	return 0;
}