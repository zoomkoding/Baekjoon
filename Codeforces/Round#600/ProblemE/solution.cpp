#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#define pii pair<int, int>
using namespace std;
int n, m, x[100001], s[100001], start = 0, best = -1, ans;
vector<pii> v;
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &x[i], &s[i]);
        v.push_back(pii(x[i] - s[i], x[i] + s[i]));
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        int left = v[i].first, right = v[i].second;
        if(left <= start){
            if(right > best) best = right;
        }
        else{
            if(best != -1){
                start = best + 1;
                i--, best = -1;
            }
            else {
                int dif = left - start;
                ans += dif;
                start = right + dif;
            }
        }
    }
    printf("%d", ans);
}