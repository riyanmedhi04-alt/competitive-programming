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
    long long MOD = 1e9 + 7;
    long long mx = 200007;
    vector<vector<long long>> dp(mx, vector<long long> (10,0));
    for(int digit = 0; digit<=9; digit++){
        dp[0][digit] = 1;
    }
    for(int ops = 1; ops<mx; ops++){
        for(int digit = 0; digit<=9; digit++){
            if(digit<9){
                dp[ops][digit] = (dp[ops-1][digit+1])%MOD;
            }else{
                dp[ops][digit] = (dp[ops-1][0] + dp[ops-1][1])%MOD;
            }
        }
    }
    while(t--){
        long long n, m;
        cin >> n >> m;
        long long res = 0;
        while(n>0){
            int d = n%10;
            n /= 10;
            res = (res + dp[m][d])%MOD;
        }
        cout << res << "\n";
    }
    return 0;
}
