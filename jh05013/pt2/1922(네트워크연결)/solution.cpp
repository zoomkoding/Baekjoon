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

vector<vector<int> > edges;

struct subset {
    int parent;
    int rank;
};

struct subset *subsets;

int find(int i){
    if(subsets[i].parent != i)subsets[i].parent = find(subsets[i].parent);
    return subsets[i].parent;
}

void Union(int x, int y){
    int xroot = find(x);
    int yroot = find(y);
    if(subsets[xroot].rank < subsets[yroot].rank) subsets[xroot].parent = yroot;
    else if(subsets[xroot].rank > subsets[yroot].rank) subsets[yroot].parent = xroot;
    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].rank ++;
    }
}

int isCycle(int t){
    int x = find(edges[t][0]);
    int y = find(edges[t][1]);
    if (x == y) return 1;
    Union(x, y);
    return 0;
}

bool compare(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int main(){
    int v, e;
    v = readInt(), e = readInt();
    edges= vector< vector<int> >(e, vector<int>(3));
    for(int i = 0; i < e; i ++)edges[i][0] = readInt(), edges[i][1] = readInt(), edges[i][2] = readInt();

    subsets = (struct subset*) malloc( (v + 1) * sizeof(struct subset) );
    for (int i = 1; i < v + 1; ++i) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    int answer = 0;
    int count = 0;

    sort(edges.begin(), edges.end(), compare);

    for(int i = 0; i < edges.size(); i++){
        if(!isCycle(i)){
            answer += edges[i][2];
            count ++;
            if(count == v - 1) break;
        }
    }

    printf("%d", answer);
}