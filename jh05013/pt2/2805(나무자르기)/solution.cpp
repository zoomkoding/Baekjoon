#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;


int main(){
    long long N, M, tree;
    vector<int> v;
    scanf("%lld %lld", &N, &M);
    for(int i = 0; i < N; i++){
        scanf("%lld", &tree);
        v.push_back(tree);
    }
    sort(v.begin(), v.end(), greater<int>());
    
    long long answer = 0;
    long long x = 0 ;
    for(int i =1; i < v.size(); i++){
        x += (v[i-1] - v[i]) * i;
        if(M == x){
            answer = v[i];
            break;
        }
        if(M > x)continue;
        else{
            answer = v[i] + (x - M) / i;
            break;
        }
    }
    
    if(answer == 0){
        int p = (M - x) / N;
        if((M-x) % N != 0) p ++;
        answer = v[v.size()-1] - p;
    }
    
    printf("%lld", answer);
    return 0;
}
