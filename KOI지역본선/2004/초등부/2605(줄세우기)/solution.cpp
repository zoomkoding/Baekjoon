#include <cstdio>
#include <vector>
#include <algorithm>
#define pii pair<int, int>
using namespace std;
int n, arr[101], pos[101];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)scanf("%d", &arr[i]);
    for(int i = 1; i <= n; i++){
        int cpos = i - arr[i];
        for(int j = i + 1; j <= n; j++){
            if(j - arr[j] <= cpos)cpos ++;
        }
        pos[i] = cpos;
    }
    vector<pii> v(n);
    for(int i = 1; i <= n; i++)v[i-1] = pii(pos[i], i);
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++)printf("%d ", v[i].second);
}