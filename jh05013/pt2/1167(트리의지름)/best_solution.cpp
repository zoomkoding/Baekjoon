#include <cstdio>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;

using pii = pair<int, int>;
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
vector<pii> vec[100000];

pii farNodeDist(int x) {
	bool hst[100000]{};
	queue<pii> q;
	q.push({ x, 0 });
	hst[x] = 1;

	int farNode = -1, farDist = -1;
	while (!q.empty()) {
		int now = q.front().X;
		int d = q.front().Y;
		q.pop();

		for (pii &next : vec[now]) {
			if (hst[next.X]) continue;
			hst[next.X] = 1;
			
			if (farDist < next.Y + d) {
				farDist = next.Y + d;
				farNode = next.X;
			}
			q.push({ next.X, next.Y + d });
		}
	}

	return { farNode, farDist };
}
int main() {
	int v = readInt();

	while (v--) {
		int n, u, d;
		n = readInt() - 1;

		while (true) {
			u = readInt();
			if (u == -1) break;
			d = readInt();
			vec[n].push_back({ --u, d });
		}
	}

	printf("%d", farNodeDist(farNodeDist(0).X).Y);

	return 0;
}