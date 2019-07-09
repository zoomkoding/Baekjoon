#include <cstdio>
#include <vector>

using namespace std; 

int main(){
    int n = 0, m = 0;
    int check[300000] = {0,};
    vector<int> v;
    while(1){
        scanf("%d", &n);
        if(n == 0) break;
        if(n > m) m = n;
        v.push_back(n);
    }
    for(int i = 2; i <= m*2; i++){
        if(check[i] == 0){
            for(int j = i*2; j <= m*2; j+=i)check[j] = 1;
        }
    }

    for(int  i = 0; i < v.size(); i++){
        int count = 0;
        for(int j = v[i]+1; j <= v[i]*2; j++) if(check[j] == 0){
            count++;
        }
        printf("%d\n", count);
    }

}