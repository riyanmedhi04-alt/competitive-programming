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
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> dp(n+1);
        // dp[i] -> minimum operations required for the element ending with i ->
        for(int i = 0; i<n; i++){
            cin >> a[i];
        }
        // since every element is >= 1 so last element has dp[i] = 1 since it can be a potential deletion;
        // also we set dp[n] = 0 for obvious reasons -> like if [3 4 1 6 7 7] .. at 4 it can be a beautiful block consuming all other right side elements so dp[n] must be set to 0 .
        dp[n] = 0;
        dp[n-1] = 1;
        for(int i = n-2; i>=0; i--){
            // if i can be such that we could potentially start a beautiful block from i then we will choose min between it should be deleted (dp[i+1]+1) or we take that block starting from i containing all i, i+1, ... i+a[i] and hence it will simply have the min ops of i+a[i] +1 element i.e dp[a[i]+1+i]->
            if(i+a[i] <= n-1){
                dp[i] = min(dp[i+1+a[i]], dp[i+1]+1);
            }else{
                // it could not start a beautiful block so , we will considered it potential deletion.
                dp[i] = dp[i+1]+1;
            }
        }
        cout << dp[0] << "\n";
    }
    return 0;

}
