#include <cstdio>
#include <vector>
using namespace std;

int n, wine[10003], taste[10003][2];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)scanf("%d", &wine[i]);
    taste[0][1] = wine[0], taste[1][1] = wine[1];
    for(int i = 0; i <= n; i++){
        taste[i+1][1] = max(taste[i+1][1], max(taste[i][0], taste[i][1]));
        taste[i+2][0] = max(taste[i+2][0], max(taste[i][0], taste[i][0]));

        if(taste[i+2][0] < taste[i][0] + wine[i+2])taste[i+2][0] = taste[i][0] + wine[i+2];
        if(taste[i+2][1] < taste[i][0] + wine[i+2])taste[i+2][1] = taste[i][0] + wine[i+2];

        if(taste[i+2][1] < taste[i][1] + wine[i+2])taste[i+2][1] = taste[i][1] + wine[i+2];
        if(taste[i+2][0] < taste[i][1] + wine[i+2])taste[i+2][0] = taste[i][1] + wine[i+2]; 
        
        if(taste[i+1][0] < taste[i][1] + wine[i+1])taste[i+1][0] = taste[i][1] + wine[i+1];
    }
    printf("%d", max(taste[n][0], taste[n][1]));
}