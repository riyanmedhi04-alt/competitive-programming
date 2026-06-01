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
    int t;
    cin >> t;
    while(t--){
        long long n, m;
        cin >> n >> m;
        vector<long long> v(n+1, INT_MAX);
        for(int i = 0; i<m; i++){
            long long x, y;
            cin >> x >> y;
            // here we stored the min limit to each friend->
            long long f = min(x,y), g = max(x,y);
            v[f] = min(v[f], g);
        }
        // careful observation->
        long long curr = n+1, ans = 0;
        for(int i = n; i>=1; i--){
            if(v[i] != INT_MAX){
                curr = min(curr, v[i]);
            }
            ans += curr - i;
        }
        cout << ans << "\n";
    }
    return 0;
}
