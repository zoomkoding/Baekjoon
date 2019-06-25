#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(pair<long long, long long> a, pair<long long, long long>b){
    return a.second < b.second;
}

int main() {
    long long n, t = 0, answer = 0;
    vector<pair<long long, long long> > v;
    cin >> n;
    for(int i = 0; i < n; i++){
      long long start, end;
      cin >> start >> end;
      v.push_back(make_pair(start, end));
    }

    sort(v.begin(), v.end());
    sort(v.begin(), v.end(), compare);

    
    for(int i = 0; i < n; i++){
      if(t <= v[i].first){
        t = v[i].second;
        answer ++;
      }
    }
    cout << answer;
}
