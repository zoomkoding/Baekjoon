#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
int t, n, arr[101][101], cnt;
char s[101];
int main(){
    scanf("%d", &t);
    for(int p = 1; p <= t; p++){
        printf("Case #%d: ", p);
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%s", s);
            for(int j = 0; j < n; j++){
                if(s[i] == '.')arr[i][j] = 1, cnt++;
            }
        }

        
    }
}