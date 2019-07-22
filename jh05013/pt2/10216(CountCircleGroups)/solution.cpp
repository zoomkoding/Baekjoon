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

int sqr(int x){return x*x;}

typedef struct Point{
    int x, y, r, v;
    Point(){}
    Point(int i, int j, int k){
        x = i;
        y = j;
        r = k;
        v = 0;
    }
}Point;

int t, n, x, y, r;
Point p[3005];

int bfs(int i){
    queue<int> q;
    p[i].v = 1;
    q.push(i);
    while(!q.empty()){
        int j = q.front(); q.pop();
        for(int k = 0; k < n; k++){
            if(!p[k].v){
                if(sqr(p[j].x-p[k].x) + sqr(p[j].y-p[k].y) <= sqr(p[j].r + p[k].r)){
                    p[k].v = 1;
                    q.push(k);
                }
            }
        }
    }
    return 1;
}

int main(){
    t = readInt();
    for(int i = 0; i < t; i++){
        n = readInt();
        for(int j = 0; j < n; j++){
            x = readInt(), y = readInt(), r = readInt();
            p[j] = Point(x, y, r);
        }
        int c = 0;
        for(int j = 0; j < n; j++){
            if(!p[j].v) {
                bfs(j);
                c++;
            }
        }
        printf("%d\n", c);
    }
   
}