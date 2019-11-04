#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define pii pair<int, int>
#define pis pair<int, string>
#define PIS pair<pii, pis>
#define X first
#define Y second
using namespace std;
int n, kor, eng, mat;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    vector<PIS> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].Y.Y >> kor >> eng >> mat;
        v[i].X.X = -kor, v[i].X.Y = eng, v[i].Y.X = -mat;
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++)cout << v[i].Y.Y << '\n';
}