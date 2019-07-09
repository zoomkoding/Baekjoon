#include <string>
#include <cstdio>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<string> v;
    map<string, int> m;
    string s = ""; 
    int n1, n2;
    scanf("%d %d", &n1, &n2);

    for(int i = 0; i < n1; i++){
        cin >> s;
        m.insert(make_pair(s, 1));
    }
    for(int i = 0; i < n2; i++){
        cin >> s;
        if(m.find(s)->second != m.end()->second) v.push_back(s);
    }
    sort(v.begin(), v.end());
    printf("%lu\n", v.size());
    for(int i = 0; i < v.size(); i++)cout << v[i] << endl;

}