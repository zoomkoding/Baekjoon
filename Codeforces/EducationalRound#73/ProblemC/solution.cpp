#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
int t, c, m, x;
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &c, &m, &x);
        int l = 0, r = 100000000, ans = 0;
        while(l <= r){
            int mid = (l + r) / 2, valid = 0;
            if(c >= mid && m >= mid && x + c - mid + m - mid >= mid){
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;  
        }
        printf("%d\n", ans);
    }
}