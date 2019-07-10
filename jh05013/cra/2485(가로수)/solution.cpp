#include <cstdio>
#include <vector>

using namespace std;

int main(){
    long long n, t1, t2, m = 10000000000;
    vector<long long> v;
    scanf("%lld %lld", &n, &t1);
    for(int i = 0; i < n-1; i++){
        scanf("%lld", &t2);
        if(m > t2-t1) m = t2-t1;
        v.push_back(t2-t1);
        t1 = t2;
    }
    while(1){
        int count = 0;
        for(int i = 0; i < v.size(); i++){
            if(v[i]%m != 0){
                count = -1;
                break;
            }
        }

        if(count != -1) {
            for(int i = 0; i < v.size(); i++)count += v[i]/m - 1; 
            printf("%d", count);
            break;
        }
        m--;
    }  
    
}