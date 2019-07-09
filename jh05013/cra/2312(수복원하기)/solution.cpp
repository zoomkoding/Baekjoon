#include <cstdio>

using namespace std;

int main(){
    int n, input;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &input);
        while(input != 1){
            for(int i = 2; i <= input; i++){
                int count = 0;
                while(input % i == 0){
                    input /= i;
                    count++;
                }
                if(count != 0)printf("%d %d\n", i, count);
            }
        }
    }
}
