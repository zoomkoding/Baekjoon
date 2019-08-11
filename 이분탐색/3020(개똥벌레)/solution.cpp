//풀이는 아래 블로그를 참고해주세요!
//zoomkoding.github.io/codingtest/2019/08/09/baekjoon-3020.html

#include <cstdio>
#include <vector>
#include <algorithm>
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

int main(){
    int n, h, t1, t2, cnt = 0, ans = 500002;
    n = readInt(), h = readInt();
    vector<int> r1(h, 0), r2(h, 0);
    for(int i = 0; i < n / 2; i++){
        t1 = readInt(), t2 = readInt();
        r1[t1-1] ++, r2[t2-1] ++;
    }
    for(int i = h - 2; i >= 0; i--) r1[i] += r1[i+1], r2[i] += r2[i+1];
    for(int i = 0; i < h; i++){
        r1[i] += r2[h - i - 1];
        if(r1[i] < ans) ans = r1[i];
    }
    for(int i = 0; i < h; i++)if(r1[i] == ans) cnt++;
    printf("%d %d", ans, cnt);
}