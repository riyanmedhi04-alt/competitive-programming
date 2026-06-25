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
    string s;
    cin >> s;
    long long MOD = 1e9 + 7;
    int n = s.size();
    string k = "";
    for(int i = 0; i<n; i++){
        if(s[i] == 'a'){
            k += s[i];
        }
        if(s[i] == 'b'){
            k += s[i];
        }
    }
    int m = k.size();
    vector<long long> dp(m+1);
    dp[0] = 0;
    long long cnt = 0;
    for(int i = 0; i<m; i++){
        if(k[i] == 'a'){
            dp[i+1] = (1+dp[i] + cnt)%MOD;
        }else{
            dp[i+1] = dp[i]%MOD;
            cnt = dp[i+1];
        }
    }
    cout << dp[m]%MOD;
    return 0;
}
