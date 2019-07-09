#include <cstdio>
#include <vector>

using namespace std;

int main(){
    long long n;
    int b, r;
    vector<char> v;
    scanf("%lld %d", &n, &b);
    while(n != 0){
        r = n%b;
        if(r < 10) v.push_back('0' + r);
        else v.push_back('A' + r - 10);
        n /= b;
    }
    for(int i = v.size()-1; i >= 0 ; i--)printf("%c", v[i]);
}