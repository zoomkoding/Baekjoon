#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;
long long n, m, t;
int main(){
    scanf("%lld", &t);
    while(t--){
        scanf("%lld", &n);
        vector<long long> ans;
        long long prev = 0, p = sqrt(n);
        for(long long i = 1; i <= p; i++){
            ans.push_back(i); 
            if(i != n / i)ans.push_back(n / i);
        }
        sort(ans.begin(), ans.end());
        printf("%lu\n0 ", ans.size() + 1);
        for(long long i = 0; i < ans.size(); i++)printf("%lld ", ans[i]);
        printf("\n");
    }
}