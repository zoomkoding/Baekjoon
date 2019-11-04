#include <iostream>
using namespace std;
long long a, b, res;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> a >> b;
    res = a * b;
    while(b){
        int x = b % 10;
        b /= 10;
        cout << a * x << '\n';
    }
    cout << res;
}