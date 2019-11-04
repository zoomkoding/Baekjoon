#include <cstdio>
#include <algorithm>
using namespace std;
int n, c, temp, a[200002], b[200002], ans[200001][2];
int main(){
    scanf("%d %d", &n, &c);
    scanf("%d", &a[1]);
    for(int i = 2; i < n; i++){
        scanf("%d", &temp);
        a[i] = a[i-1] + temp;
    }
    scanf("%d", &b[1]);
    for(int i = 2; i < n; i++){
        scanf("%d", &temp);
        b[i] = b[i-1] + temp;
    }
    
    for(int i = 1; i < n; i++){
        int emin = 987654321, wmin = 987654321;
        for(int j = 0; j < i; j++){
            int e, w;
            if(el[j]){
                e = ans[j] + b[i] - b[j]; 
                w = ans[j] + a[i] - a[j];
            }
            else{
                e = ans[j] + b[i] - b[j] + c; 
                w = ans[j] + a[i] - a[j];
            }
            if(emin > e)emin = e;
            if(wmin > w)wmin = w;
        }
        if(emin > wmin) ans[i] = wmin;
        else ans[i] = emin, el[i] = 1;
        
    }
    for(int i = 0; i < n; i++)printf("%d ", ans[i]);
}