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
        vector<long long> sizes(n);
        for(int i = 0; i<n; i++){
            cin >> sizes[i];
        }
        vector<long long> dp(n+1);
        // dp[i] -> length of longest valid sequence
        // initialize the dp with 1 for each element since the model can itself be taken.
        for(int i = 0; i<=n; i++){
            dp[i] = 1;
        }
        for(int i = 1; i<=n; i++){
            // here we used a trick that we will only care about those j which are divisible by i i.e i*2, i*3.. etc etc (this optimizes the solution to O(nlogn))->
            for(int j = 2*i; j<=n; j += i){
                if(sizes[j-1] > sizes[i-1]){
                    dp[j] = max(dp[i]+1,dp[j]);
                }
            }
        }
        long long ans = 0;
        for(int i = 0; i<=n; i++){
            ans = max(dp[i],ans);
        }
        cout<< ans << "\n";
    }
    return 0;

}
