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
    int n, c, r, l, answer;
    n = readInt(), c = readInt();
    vector<int> v(n);
    for(int i = 0; i < n; i++) v[i] = readInt();
    sort(v.begin(), v.end());
    l = 1, r = v[n - 1] - v[0];
    while(r >= l){
        int mid = (l + r) / 2;
        int p = 0, t = 1;
        for(int i = 1; i < n; i++){
            if(v[i] - v[p] >= mid){
                t ++;
                p = i;
            }
        }
        if(t >= c){            
            answer = mid;
            l = mid + 1;
        } 
        else r = mid - 1;  
    }
    printf("%d", answer);
}
