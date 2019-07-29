#include <cstdio>
#include <queue>

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
    int n, m;
    n = readInt();
    priority_queue<int, vector<int>, less<int> > pq1;
    priority_queue<int, vector<int>, greater<int> > pq2;
    for(int i = 0; i < n; i++){
        m = readInt();
        if(pq1.size() == pq2.size() + 1)pq2.push(m);
        else pq1.push(m);
        
        if(!pq1.empty() && !pq2.empty() && pq1.top() > pq2.top()){
            int temp = pq2.top(); pq2.pop();
            pq2.push(pq1.top()); pq1.pop();
            pq1.push(temp);
        }
        printf("%d\n", pq1.top());
    }
}