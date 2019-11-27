#include <cstdio>
#include <algorithm>
using namespace std;
long long n, m, arr[200001], ans[200001];
int main(){
    scanf("%lld %lld", &n, &m);
    for(int i = 0; i < n; i++)scanf("%lld", &arr[i]);
    sort(arr, arr + n);
    for(int i = 1; i < n; i++)arr[i] += arr[i - 1];
    for(int i = 0; i < m; i++)ans[i] = arr[i];
    for(int i = m; i < n; i++)ans[i] = arr[i] + ans[i - m];
    for(int i = 0; i < n; i++)printf("%lld ", ans[i]);
}