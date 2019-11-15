#include <string>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
int t, x, y;
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &x, &y);
        if(x > 3)printf("YES\n");
        else if(x == 3 && y <= 3)printf("YES\n");
        else if(x == 2 && y <= 3)printf("YES\n");
        else if(x == 1 && y == 1)printf("YES\n");
        else printf("NO\n");
    }
        
}