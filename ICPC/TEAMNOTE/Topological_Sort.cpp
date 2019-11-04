#include <cstdio>
#include <vector>
using namespace std;

int n, in[501], w[501], ans[501], visited[501];
vector<vector<int> > e;
int main(){
    scanf("%d", &n);
    e = vector<vector<int> >(n+1);
    for(int i = 1; i <= n; i++){
        scanf("%d", &w[i]);
        while(1){
            int t;
            scanf("%d", &t);
            if(t == -1)break;
            //다리 만들어주고
            e[t].push_back(i);
            //인커밍 에지의 수를 추가
            in[i]++;
        }
    }
    //모든 원소가 추가될때까지 진행
    for(int i = 0; i < n; i++){
        //인커밍 에지가 없는 애를 찾아서
        for(int j = 1; j <= n; j++){
            if(visited[j] || in[j])continue;
            //처리해주고
            ans[j] += w[j];
            visited[j] = 1;
            //해당 원소와 연결된 애들과의 연결을 끊어
            for(int k = 0; k < e[j].size(); k++){
                int next = e[j][k];
                in[next] --;
                if(ans[next] < ans[j])ans[next] = ans[j];
            }
            break;
        }
    }
    for(int i = 1; i <= n; i++)printf("%d\n", ans[i]);
}