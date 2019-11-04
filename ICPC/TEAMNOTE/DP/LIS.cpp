#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int ans, n, t, arr[201];
int vector<int> v;
main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &t);
        arr[t] = i;
    }
    for(int i = 1; i <= n; i++){
        int r = arr[i];
        if(!ans || v[ans-1] < r)v.push_back(r), ans++;
        else v[upper_bound(v.begin(), v.end(), r)-v.begin()] = r;
    }
    printf("%d", n - ans);
}