#include <cstdio>
#include <vector>
using namespace std;
int n, in1[10], in2[10], MIN[10], MAX[10];
char c;
vector<int> e[10];
int main(){
    scanf("%d ", &n);
    for(int i = 0; i < n; i++){
        c = getchar();
        if(c == '<'){
            e[i+1].push_back(i);
            in1[i]++, in2[i]++;
        }
        else {
            e[i].push_back(i+1);
            in1[i+1]++, in2[i+1]++;
        }
        getchar();
    }
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(!in1[j]){
                MAX[j] = 9 - i, in1[j] = 1;
                for(int k = 0; k < e[j].size(); k++) in1[e[j][k]]--;
                break;
            }
        }
        for(int j = n; j >= 0; j--){
            if(!in2[j]){
                MIN[j] = n - i, in2[j] = 1;
                for(int k = 0; k < e[j].size(); k++) in2[e[j][k]]--;
                break;
            }
        }
    }
    for(int i = 0; i <= n; i++) printf("%d", MAX[i]);
    printf("\n");
    for(int i = 0; i <= n; i++) printf("%d", MIN[i]);
}