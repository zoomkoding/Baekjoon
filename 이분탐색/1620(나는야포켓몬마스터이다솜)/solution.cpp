#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define psi pair<string, int>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m;
    string temp;
    cin >> n >> m;
    vector<psi> s(n); 
    vector<string> v(n);
    for(int i = 0; i < n; i++){
        cin >> temp;
        s[i] = psi(temp, i);
        v[i] = temp;
    }
    sort(s.begin(), s.end());
    for(int i = 0; i < m; i++){
        cin >> temp;
        if(temp[0] > '9') cout << s[upper_bound(s.begin(), s.end(), psi(temp, -1)) - s.begin()].second + 1<< '\n';
        else cout << v[stoi(temp) - 1] << '\n'; 
    }
}