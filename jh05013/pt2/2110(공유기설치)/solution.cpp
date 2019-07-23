#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

char in[20000000];
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

int answer;

int binarySearch(vector<int> &v, int l, int r, int c, int n){
    int t, p, mid;
    if(r >= l){
        mid = (l + r) / 2;
        p = 0, t = 1;
        for(int i = 1; i < n; i++){
            if(v[i] - v[p] >= mid){
                t ++;
                p = i;
            }
        }
        if(t >= c) {
            answer = mid;
            return binarySearch(v, mid + 1, r, c, n);
        }
        else return binarySearch(v, l, mid - 1, c, n);  
    }
    return -1;
}

int main(){
    getIn();
    int n, c;
    n = nextInt(), c = nextInt();
    vector<int> v(n);
    for(int i = 0; i < n; i++) v[i] = nextInt();
    sort(v.begin(), v.end());
    binarySearch(v, 1, v[n-1]-v[0], c, n);
    printf("%d", answer);
}
