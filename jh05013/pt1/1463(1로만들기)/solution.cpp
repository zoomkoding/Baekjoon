#include <cstdio>
#include <vector>

using namespace std;

#define INF 10000000
int n;
int main(){
    vector<int> arr(3000010, INF);
    scanf("%d", &n);
    arr[1] = 0;
    for(int i = 1; i <= 1000000; i++){
        int v = arr[i] + 1;        
        if(v < arr[i*3])arr[i*3] = v;
        if(v < arr[i*2])arr[i*2] = v;
        if(v < arr[i+1])arr[i+1] = v;
    }
    printf("%d", arr[n]);
}