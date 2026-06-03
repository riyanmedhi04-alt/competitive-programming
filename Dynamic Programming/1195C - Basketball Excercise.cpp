#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<long long> h1(n), h2(n);
    for(int i = 0; i<n; i++){
        cin >> h1[i];
    }
    for(int i = 0; i<n; i++){
        cin >> h2[i];
    }
    vector<long long> dp1(n), dp2(n), dp3(n);
    // dp1 -> for max height if we have h1 for posn i
    // dp2 -> same as dp1 but for h2
    // dp3 -> if we dont choose any player at current i.
    dp1[0] = h1[0];
    dp2[0] = h2[0];
    dp3[0] = 0;
    for(int i = 1; i<n; i++){
        dp1[i] = max(dp2[i-1] + h1[i] , max(dp3[i-1] + h1[i], h1[i]));
        dp2[i] = max(dp1[i-1] + h2[i], max(dp3[i-1] + h2[i], h2[i]));
        dp3[i] = max(dp1[i-1], max(dp2[i-1], dp3[i-1]));
    }
    cout << max(dp1[n-1], max(dp2[n-1], dp3[n-1]));
    return 0;
}
