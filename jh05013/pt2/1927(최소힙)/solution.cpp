#include <cstdio>
#include <queue>

using namespace std;

int main(){
    int n, input;
    priority_queue<int, vector<int>, greater<int> > pq;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &input);
        if(!input){
            if(!pq.empty())printf("%d\n", pq.top()), pq.pop();
            else printf("0\n");
        }
        else pq.push(input);
    }
}