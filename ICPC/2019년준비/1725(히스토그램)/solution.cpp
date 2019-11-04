#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

namespace fio {
	const int BSIZE = 524288;
	char buffer[BSIZE];
	char *p = buffer + BSIZE;
	inline char readChar() {
		if (p == buffer + BSIZE) {
			fread(buffer, 1, BSIZE, stdin);
			p = buffer;
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

int n, input, answer = 0;

int find_min(vector<int> &a, vector<int> &tree, int node, int start, int end, int left, int right){
    if (left > end || right < start) return -1;
    if (left <= start && end <= right) return tree[node];
    
    int c1 = find_min(a, tree, node*2, start, (start+end)/2, left, right);
    int c2 = find_min(a, tree, node*2+1, (start+end)/2+1, end, left, right);
    if(c1 == -1) return c2;
    if(c2 == -1) return c1;
    return a[c1] < a[c2] ? c1 : c2;
    
}

long long div_and_conq(int left, int right, vector<int> &v, vector<int> &tree){
    int min = find_min(v, tree, 1, 0, v.size()-1, left, right);
    long long box = (long long)v[min]*(long long)(right-left+1);
    if(left <= min - 1){
        long long temp = div_and_conq(left, min -1, v, tree);
        if(box < temp) box = temp;
        
    }
    if(min + 1 <= right) {
        long long temp = div_and_conq(min + 1, right, v, tree);
        if(box < temp) box = temp;
    }
    return box;
}

// a: 배열 a
// tree: 세그먼트 트리
// node: 세그먼트 트리 노드 번호
// node가 담당하는 합의 범위가 start ~ end

void init(vector<int> &a, vector<int> &tree, int node, int start, int end){
    if(start == end) tree[node] = start;
    else{
        init(a, tree, node*2, start, (start+end)/2);
        init(a, tree, node*2 + 1, (start+end)/2 + 1, end);
        tree[node] = a[tree[node*2]] < a[tree[node*2+1]] ? tree[node*2] : tree[node*2+1];
    } 
}

int main(){
    n = fio::readInt();
    answer = 0;
    int h = (int)(ceil(log2(n))+1e-9);
    int tree_size = (1 << (h+1));

    vector<int> v(n);
    vector<int> tree(tree_size);

    for(int i = 0; i < n; i++)v[i] = fio::readInt();
    init(v, tree, 1, 0, n-1);
    printf("%lld\n", div_and_conq(0, n-1, v, tree));
}