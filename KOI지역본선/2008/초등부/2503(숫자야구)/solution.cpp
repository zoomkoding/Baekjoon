#include <cstdio>
int n, num, st, b, invalid[1000];
int main(){
    scanf("%d", &n);
    for(int i = 123; i < 988; i++){
        int x = i / 100, y = (i % 100) / 10, z = i % 10;
        if(x == y || x == z || y == z)invalid[i] = 1;
        if(x == 0 || y == 0 || z == 0)invalid[i] = 1;
    }
    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &num, &st, &b);
        int nx = num / 100, ny = (num % 100) / 10, nz = num % 10;        
        for(int j = 123; j < 988; j++){
            if(invalid[j])continue;
            int x = j / 100, y = (j % 100) / 10, z = j % 10;
            int S = (x == nx) + (y == ny) + (z == nz);
            int B = (x == ny) + (x == nz) + (y == nx) + (y == nz) + (z == nx) + (z == ny); 
            if(S != st || B != b)invalid[j] = 1;
        }
    }
    int ans = 0;
    for(int i = 123; i < 988; i++){
        if(invalid[i] == 0)ans ++;
    }
    printf("%d", ans);
}