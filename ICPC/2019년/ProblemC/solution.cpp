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

long long a[51];

int main(){
    int n, feedback = 0, price = 0;
    long long w, st = 0;
    scanf(" %d %lld", &n, &w);
    for(int i = 0; i < n; i++)
        scanf(" %lld", &a[i]);

    feedback = 1;
    st = (long long)(w / a[0]);
    w %= a[0];
    for(int i = 1; i < n; i++) {
        if(feedback && a[i-1] > a[i]) {
            w += a[i-1] * st;
            feedback = 0;
            st = 0;
        }
        else if(!feedback && a[i-1] < a[i]) {
            st = (long long)(w / a[i-1]);
            w -= st * a[i-1];
            feedback = 1;
            price = a[i-1];
        }
    }
    if(a[n-2] < a[n-1]) {
        w+=a[n-1]*st;
    }
    else
    {
        w += price * st;
    }

    printf("%lld", w);
}