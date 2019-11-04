#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

int n, v1, v2, ans = 987654321, w1[251], w2[251], arr1[251][4], arr2[250][4];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d %d", &w1[i], &w2[i]);
    for(int i = 1; i <= n; i++){
        int d1, d2, d3, d4;
        //AA
        int x1, y1, x2, y2;
        x1 = arr1[i-1][0] + w1[i], y1 = arr2[i-1][0];
        x2 = arr1[i-1][1] + w1[i], y2 = arr2[i-1][1];
        if(max(x1, y1) < max(x2, y2))arr1[i][0] = x1, arr2[i][0] = y1;
        else arr1[i][0] = x2, arr2[i][0] = y2;
        //BA
        x1 = arr1[i-1][2] + w1[i], y1 = arr2[i-1][2];
        x2 = arr1[i-1][3] + w1[i], y2 = arr2[i-1][3];
        if(max(x1, y1) < max(x2, y2))arr1[i][1] = x1, arr2[i][1] = y1;
        else arr1[i][1] = x2, arr2[i][1] = y2;
        //BB

        x1 = arr1[i-1][2], y1 = arr2[i-1][2] + w2[i];
        x2 = arr1[i-1][3], y2 = arr2[i-1][3] + w2[i];
        if(max(x1, y1) < max(x2, y2))arr1[i][2] = x1, arr2[i][2] = y1;
        else arr1[i][2] = x2, arr2[i][2] = y2;
        //AB
        x1 = arr1[i-1][0], y1 = arr2[i-1][0] + w2[i];
        x2 = arr1[i-1][1], y2 = arr2[i-1][1] + w2[i];
        if(max(x1, y1) < max(x2, y2))arr1[i][3] = x1, arr2[i][3] = y1;
        else arr1[i][3] = x2, arr2[i][3] = y2;
        
        for(int j = 0; j < 4; j++){
            printf("%d %d\n", arr1[i][j], arr2[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i < 4; i++){
        int M = max(arr1[n][i], arr2[n][i]);
        if(M < ans)ans = M;
    }
    printf("%d", ans);
}