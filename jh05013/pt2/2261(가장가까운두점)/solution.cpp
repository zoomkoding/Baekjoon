#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
} 
bool comp(const pair<int,int> &a, const pair<int,int> &b)
{
    return a.second < b.second;
}

int main(){
    int n, x, y; int m = 1000000000;
    float c = 300000.0;
    vector<pair<int, int> > v;
    set<pair<int, int> > s;
    scanf("%d", &n);
    while(n--){
        scanf("%d %d", &x, &y);
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size() - 1; i++){
        vector<pair<int, int> > v2;
        for(int j = i + 1; j < v.size(); j++){
            int diff_x = v[j].first - v[i].first;
            if(diff_x * diff_x > m)break;
            v2.push_back(v[j]);
        }
        sort(v2.begin(), v2.end(), sortbysec);
        int lo_it = lower_bound(v2.begin(), v2.end(), pair<int,int>(0, v[i].second-c), comp) - v2.begin();
        int up_it = upper_bound(v2.begin(), v2.end(), pair<int,int>(0, v[i].second+c), comp) - v2.begin();

        for(int j = lo_it; j < up_it; j++){
            int diff_x = v[i].first - v2[j].first, diff_y = v[i].second - v2[j].second;
            int d = diff_x * diff_x + diff_y * diff_y;
            if(d < m){
                m = d;
                c = sqrt(m);
            } 
        }
    }
    printf("%d", m);
}