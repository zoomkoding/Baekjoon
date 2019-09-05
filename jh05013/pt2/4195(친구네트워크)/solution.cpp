#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;


int k, n;
string f1, f2;
map<string, int> name;
int par[100020], cnt[100020];

int find(int root){
    if(!par[root])return root;
    return find(par[root]);
}
void Union(int v1, int v2){
    int p1 = find(v1), p2 = find(v2);
    if(p1 != p2) cnt[p1] += cnt[p2], par[p2] = p1;
    cout << cnt[p1] << '\n';
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> k;
    while(k--){
        int num = 1;
        cin >> n;
        for(int i = 0; i < n + 2; i++)par[i] = 0, cnt[i] = 1;
        while(n--){
            cin >> f1 >> f2;
            if(name.find(f1) == name.end())name.insert(make_pair(f1, num++));
            if(name.find(f2) == name.end())name.insert(make_pair(f2, num++));
            Union(name.find(f1)->second, name.find(f2)->second);
        }
    }
}