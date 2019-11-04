#include <bits/stdc++.h>

using namespace std;

vector <int> a;

int main() {
	int w, n, tmp;
	long long ans = 0;
	scanf("%d %d", &w, &n);
	
	for(int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		a.push_back(tmp);
	}
	
	sort(a.begin(), a.end());
	
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
	
	for(int s = 0, e = n-1; s <= e; ) {
		if(a[s]+a[e] <= w) {
			long long sq = (w-a[s]-a[e]) * (w-a[s]-a[e]);
			e--;
			s++;
			if(ans < sq)
				ans = sq;
		}
		else {
			long long sq = (w-a[e]) * (w-a[e]);
			e--;
			if(ans < sq)
				ans = sq;
		}
	}
	printf("%lld", ans);
    
    return 0;
}