#include <cstdio>
#include <vector>
using namespace std;
#define INF 1000001

int d[1003][3];
int rgb[1003][3];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 3; j++)d[i][j] = INF;
    }
    for(int i = 0; i < n; i++) scanf("%d %d %d", &rgb[i][0], &rgb[i][1], &rgb[i][2]);
    d[0][0] = rgb[0][0], d[0][1] = rgb[0][1], d[0][2] = rgb[0][2];
    for(int i = 0; i < n; i++){
        if(d[i + 1][0] > d[i][1] + rgb[i+1][0]) d[i + 1][0] = d[i][1] + rgb[i+1][0];
        if(d[i + 1][0] > d[i][2] + rgb[i+1][0]) d[i + 1][0] = d[i][2] + rgb[i+1][0];
        if(d[i + 1][1] > d[i][0] + rgb[i+1][1]) d[i + 1][1] = d[i][0] + rgb[i+1][1];
        if(d[i + 1][1] > d[i][2] + rgb[i+1][1]) d[i + 1][1] = d[i][2] + rgb[i+1][1];
        if(d[i + 1][2] > d[i][0] + rgb[i+1][2]) d[i + 1][2] = d[i][0] + rgb[i+1][2];
        if(d[i + 1][2] > d[i][1] + rgb[i+1][2]) d[i + 1][2] = d[i][1] + rgb[i+1][2];
    }
    
    printf("%d", min(min(d[n][0], d[n][1]),d[n][2]));
}