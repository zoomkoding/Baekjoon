#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
// 1. 1080 2352 1138
// 2. 2146 1963 9019
// 3. 7453 1072 1939
// 4. 11585 10266
// 5. 9938 3780
// 6. 1916 6593 6118
// 7. 2011 10942 9507 10164 2631 5557
// 8. 10159 2458
// 9. 1068 9237
// 10. 1725 1935
// 11. 9372 1647 6497
// 12. 1516 2529
// 13. 11812 1626


int main(){
    int arr[] = {1080, 2352, 1138, 2146, 1963, 9019, 7453, 1072, 1939, 11585, 10266, 9938, 3780, 1916, 6593, 6118, 2011, 10942, 9507, 10164, 2631, 5557, 10159, 2458, 1068, 9237, 1725, 1935, 9372, 1647, 6497, 1516, 2529, 11812, 1626};
    int length = sizeof(arr)/sizeof(int);
    srand((unsigned)time(NULL));
    sort(arr, arr+length); 
    for(int i = 0; i < 35; i++){
        printf("%d\n", arr[i]);
    }
}