#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
// check1 -> for returning the powers of 2 required to satisfy the target
int check1(long long x){
    int cnt = 0;
    for(int bit = 0; bit<60; bit++){
        if(x & (1LL<<bit)){
            cnt++;
        }
    }
    return cnt;
}
// recursive fn ->
void solve(int idx, long long curr, long long cnt, vector<long long> &fact, long long &ans){
    if(curr<0){
        return;
    }
    if(idx == fact.size()){
        int bit_req = check1(curr);
        ans = min(ans, cnt + bit_req);
        return;
    }
    solve(idx+1, curr - fact[idx], cnt+1, fact, ans);
    solve(idx+1, curr, cnt, fact, ans);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        vector<long long> fact;
        long long p = 2;
        for(int i = 3; i<15; i++){
            p *= i;
            fact.push_back(p);
        }
        long long ans = 1e15;
        solve(0,n,0,fact, ans);
        cout << ans << "\n";
    }
    return 0;
}
