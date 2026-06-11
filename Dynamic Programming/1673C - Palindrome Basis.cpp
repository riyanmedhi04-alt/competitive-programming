#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
bool isPalindrome( int n){
    string s = to_string(n);
    int l = 0;
    int r = s.size() -1;
    while(l<r){
        if(s[l] != s[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
        vector<int> v;
        const int maxm = 40000;
        const long long MOD = 1e9 + 7;
        for(int i = 1; i<= maxm; i++){
            if(isPalindrome(i)){
                v.push_back(i);
            }
        }
        vector<long long> dp(maxm+1, 0);
        dp[0] = 1;
        for(int x : v){
            for(int s = x; s<=maxm; s++){
                dp[s] = (dp[s] + dp[s-x])%MOD;
            }
        }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}
