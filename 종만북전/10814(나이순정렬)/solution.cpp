#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define pii pair<int, int>
#define pis pair<pii, string>
#define X first
#define Y second
using namespace std;
int n;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    vector<pis> v(n);
    for(int i = 0; i < n; i++){
        v[i].X.Y = i;
        cin >> v[i].X.X >> v[i].Y;
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++)cout << v[i].X.X << ' ' << v[i].Y << '\n';
}