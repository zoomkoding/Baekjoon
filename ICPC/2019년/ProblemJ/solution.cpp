#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

int d[100001], d_i[100001], p[100001], s[100001];
long long z[100001];

int main(){
    int n;
    scanf(" %d", &n);
    for(int i = 0; i < n-1; i++)
        scanf(" %d", &d[i]);
    
    d_i[n-2] = d[n-2];
    for(int i = n-3; i >= 0; i--)
        d_i[i] = d_i[i+1] + d[i];
    
    for(int i = 0; i < n-1; i++)
        scanf(" %d %d", &p[i], &s[i]);
    z[0] = 0;
    long long ans = d_i[0] * s[0] + p[0];
    int tmp_s = s[0], tmp_i = 0, tmp_p = p[0];
    for(int i = 1; i < n-1; i++) {
        if(tmp_s > s[i]) {
            long long now = d_i[i] * s[i] + p[i];
            long long prev = (d_i[tmp_i] - d_i[i]) * tmp_s + tmp_p;
            if(now + prev + z[tmp_i] < ans) {
                ans = now + prev + z[tmp_i];
                z[i] = prev + z[tmp_i];
                tmp_s = s[i];
                tmp_i = i;
                tmp_p = p[i];
            }
        }
    }

    printf("%lld", ans);
}