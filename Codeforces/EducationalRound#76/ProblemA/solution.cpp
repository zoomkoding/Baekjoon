#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int t, n, x, a, b;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d %d", &n, &x, &a, &b);
        if(a > b)swap(a, b);
        printf("%d\n", b - a + min(a - 1 + n - b, x));
    }
}