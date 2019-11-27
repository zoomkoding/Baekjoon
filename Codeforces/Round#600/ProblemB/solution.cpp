#include <cstdio>
#include <vector>
using namespace std;
int n, arr[1000001], cur, date = 1, valid = 1, office[1000001], day[1000001];
vector<int> v;
int main(){

    scanf("%d", &n);
    for(int i = 0; i < n; i++)scanf("%d", &arr[i]);
    for(int i = 0; i < n; i++){
        int who = 0;
        if(arr[i] < 0){
            who = -arr[i];
            if(office[who] == 0){
                valid = 0;
                break;
            }
            cur--;
            office[who]--;
            if(cur == 0){
                v.push_back(i);
                date++;
            }
        }
        else{
            who = arr[i];
            if(office[who] == 1){
                valid = 0;
                break;
            }
            if(day[who] == date){
                valid = 0;
                break;
            }
            office[who]++;
            day[who] = date;
            cur++;
        } 
    }
    if(cur != 0)valid = 0;
    if(valid){
        printf("%lu\n", v.size());
        printf("%d ", v[0] + 1);
        for(int i = 1; i < v.size(); i++){
            printf("%d ", v[i] - v[i - 1] );
        }
    }
    else printf("-1");
}