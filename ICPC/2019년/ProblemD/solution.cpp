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

int n, ans;

vector <pair<int, int> > x, y;

int main(){
    int n, a, b;
    scanf(" %d", &n);

    for(int i = 0; i < n; i++) {
        scanf(" %d %d", &a, &b);
        x.push_back(make_pair(a, b));
        y.push_back(make_pair(b, a));
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    printf("x min : %d %d\n", x[0].first, x[0].second);
    printf("x max : %d %d\n", x[n-1].first, x[n-1].second);
    printf("y min : %d %d\n", y[0].first, y[0].second);
    printf("y max : %d %d\n", y[n-1].first, y[n-1].second);
}