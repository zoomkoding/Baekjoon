#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m, input;
    vector<int> v;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &input);
        v.push_back(input);
    }
    sort(v.begin(), v.end());
    scanf("%d", &m);
    while(m--){
        scanf("%d", &input);
        if(binary_search(v.begin(), v.end(), input)) printf("1\n");
        else printf("0\n");
    }
}