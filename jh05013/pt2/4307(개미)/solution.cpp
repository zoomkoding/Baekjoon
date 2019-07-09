#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int test_num, l, n;
    cin >> test_num;
    for(int i = 0; i < test_num; i++){
      cin >> l >> n;
      int mid = l / 2;
      int shortest = 0, longest = 0, temp = 0;
      for(int i = 0; i < n; i++){
        cin >> temp;
        if(temp > mid) {
          if(shortest < l - temp) shortest = l - temp;
          if(longest < temp) longest = temp;
        }
        else{
          if(shortest < temp) shortest = temp;
          if(longest < l - temp) longest = l - temp;
        }
      }
      cout << shortest << " " << longest << endl;
    }
}
