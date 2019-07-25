#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

char in[2000000];
const char* o;

void getIn() {
    o = in;
    in[fread(in, 1, sizeof(in) - 4, stdin)] = '\n';
}

int nextInt() {
    int ret = 0;
    while (*o < '0' || *o > '9') ++o;
    while (*o >= '0' && *o <= '9') ret = 10 * ret + *o++ - '0';
    return ret;
}

int main(){
    getIn();
    int n, c, r, l, answer, mid, p, t, i;
    n = nextInt(), c = nextInt();
    vector<int>v(n);
    for(int i = 0; i < n; i++) v[i] = nextInt();
    sort(v.begin(), v.end());
    l = 1, r = v[n - 1] - v[0];
    while(r >= l){
        mid = (l + r) / 2;
        p = 0, t = 1;
        for(i = 1; i < n; i++){
            if(v[i] - v[p] >= mid){
                t ++;
                p = i;
            }
        }
        if(t >= c){            
            answer = mid;
            l = mid + 1;
        } 
        else r = mid - 1;  
    }
    printf("%d", answer);
}
