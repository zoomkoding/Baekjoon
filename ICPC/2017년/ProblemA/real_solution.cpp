#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

struct Point {
    int x, y;
    Point() {
    }
    Point(int x, int y) : x(x), y(y) {
    }
    bool operator < (const Point &v) const {
        if (y == v.y) {
            return x < v.x;
        } else {
            return y < v.y;
        }
    }
};

bool cmp(const Point &u, const Point &v) {
    return u.x < v.x;
}
int dist(Point p1, Point p2) {
    return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}

using namespace std;

int main(){
    int n, x, y, m, c, x_diff;
    Point p1, p2;
    scanf("%d", &n);
    vector<Point> v(n);
    for(int i = 0; i < n; i++)scanf("%d %d", &v[i].x, &v[i].y);
    sort(v.begin(), v.end(),cmp);
    m = dist(v[0], v[1]);
    set<Point> s; s.insert(v[0]), s.insert(v[1]);
    int start = 0;
    for(int i = 2; i < n; i++){
        p1 = v[i];
        while(start < i){
            p2 = v[start];
            x_diff = p2.x-p1.x;
            //더 크다는 것은 거리가 멀다는 거니까 계속 erase해주면 됨
            if(x_diff*x_diff > m) {
                s.erase(p2);
                start++;
            }
            else break;
        }
        int d = (int)(sqrt((double)m)+1);
        auto up = s.upper_bound(Point(100000, p1.y+d));
        auto low = s.lower_bound(Point(-100000, p1.y-d));
        while(low!=up){
            int temp = dist(p1, *low);
            if(temp < m) m = temp;  
            low++;
        }
        s.insert(p1);
    }
    printf("%d", m);
}