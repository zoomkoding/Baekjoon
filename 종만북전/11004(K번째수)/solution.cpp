#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i < n; i++)cin >> v[i];
    sort(v.begin(), v.end());
    cout << v[m-1];
}