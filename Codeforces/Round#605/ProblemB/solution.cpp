#include <cstdio>
#include <algorithm>
using namespace std;
int t, arr[4], minRL, minUD, ans;
char s[1000001];
int main(){
    scanf("%d", &t);
    while(t--){
        int cnt = 0;
        scanf("%s", s);
        for(int i = 0; i < 4; i++)arr[i] = 0;
        for(int i = 0; s[i] != '\0'; i++){
            if(s[i] == 'L')arr[0]++;
            else if(s[i] == 'R')arr[1]++;
            else if(s[i] == 'U')arr[2]++;
            else if(s[i] == 'D')arr[3]++;
            cnt++;
        }
        minRL = min(arr[0], arr[1]), minUD = min(arr[2], arr[3]);
        if(minRL == 0 && minUD != 0)minUD = 1;
        if(minUD == 0 && minRL != 0)minRL = 1;
        ans = minRL + minUD;
        printf("%d\n", ans * 2);
        if(ans == 0)continue;
        for(int i = 0; i < minRL; i++)printf("L");
        for(int i = 0; i < minUD; i++)printf("U");
        for(int i = 0; i < minRL; i++)printf("R");
        for(int i = 0; i < minUD; i++)printf("D");
        printf("\n");
    }
}