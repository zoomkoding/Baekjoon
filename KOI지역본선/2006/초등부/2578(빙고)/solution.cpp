#include <cstdio>
int x[25], y[25], call[25], temp, h[6], v[6], d1, d2, cnt;
int main(){
    for(int i = 1; i < 6; i++){
        for(int j = 1; j < 6; j++){
            scanf("%d", &temp);
            x[temp] = i, y[temp] = j;
        }
    }
    for(int i = 0; i < 25; i++)scanf("%d", &call[i]);
    for(int i = 0; i < 25; i++){
        temp = call[i];
        h[x[temp]]++, v[y[temp]]++;
        if(x[temp] == y[temp]){
            d1++;
            if(d1 == 5)cnt ++;
        }
        if(x[temp] + y[temp] == 6){
            d2++;
            if(d2 == 5)cnt ++;
        }
        if(h[x[temp]] == 5)cnt++;
        if(v[y[temp]] == 5)cnt++;
        
        if(cnt >= 3){
            printf("%d", i + 1);
            break;
        }
    }
}