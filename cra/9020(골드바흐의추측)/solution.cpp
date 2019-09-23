#include <cstdio>
#include <vector>

using namespace std; 

int main(){
    int n, k, m = 0, check[10000] = {0,};
    scanf("%d", &n);
    vector<int> v;
    while(n--){
        scanf("%d", &k);
        if(k > m) m = k;
        v.push_back(k);
    }
    for(int i = 2; i <= m; i++){
        if(check[i] == 0){
            for(int j = i*2; j <= m; j+=i)check[j] = 1;
        }
    }

    for(int i = 0; i < v.size(); i++){
        for(int j = v[i]/2 ; j < v[i]; j++){
            if(!check[j] && !check[v[i]-j]) {
                printf("%d %d\n", v[i]-j, j);
                break;
            }
        }
    }

}