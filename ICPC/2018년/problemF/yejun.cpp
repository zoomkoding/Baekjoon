#include<bits/stdc++.h>

using namespace std;

vector<int> v;
bitset<800000> b[4], tmp;

int main(void){
	int  w, n, t;
	scanf("%d %d", &w, &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &t);
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	
	for(int i = 0; i < n; i++)
		b[0].set(v[i], true);
	
	for(int i = 1; i < 4; i++)
		for(int j = 0; j < n; j++) {
			tmp = b[i-1] >> v[j];
			b[i] |= tmp;
		}
		
	printf("%s", b[3].test(0) ? "YES" : "NO");
	
	return 0;
}