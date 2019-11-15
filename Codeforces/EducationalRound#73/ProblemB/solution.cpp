#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int n, m;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        if(n % 2 == 0)m = !m;
        for(int j = 0; j < n; j++){
            if(m == 0)printf("W");
            else printf("B");
            m = !m;
        }
        printf("\n");
    }
}