#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
char s[1000001];
int q, n, k;

int main(){
    scanf("%d", &q);
    while(q--){
        scanf("%d %d", &n, &k);
        scanf("%s", s);
        
            int search = 0, to = -1, sw = 0;
            for(int i = 0; i < n; i++){
                if(search == 1){
                    if(s[i] == '0'){
                        if(i - to < k){
                            sw = 1;
                            swap(s[to], s[i]);
                            k -= i - to; 
                            break;
                        }
                        else {
                            sw = 1;
                            swap(s[i - k], s[i]);
                            k -= k;
                        }
                    }
                }
                if(search == 0 && s[i] == '1')search = 1, to = i;
            }
            if(sw == 0)break;
        }
        printf("%s\n", s);
    }
    
}