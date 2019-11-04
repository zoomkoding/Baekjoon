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

vector<int> v[4];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i * i <= 50000; i++) {
        v[0].push_back(i*i);
        if(i*i == n) {
            printf("1");
            return 0;
        }

    }
    
    int Size = v[0].size(), feedback = 0;
    for(int k = 1; k <= 3; k++) {
        int kSize = v[k-1].size();
        for(int i = 0 ; i < kSize; i++) {
            for(int j = 0; j < Size; j++) {
                if(v[k-1][i] + v[0][j] <= 50000) {
                    v[k].push_back(v[k-1][i] + v[0][j]);
                    if(v[k-1][i] + v[0][j] == n) {
                        printf("%d", k+1);
                        feedback = 1;
                        return 0;
                    }
                }
            }
        }
    }
    
}