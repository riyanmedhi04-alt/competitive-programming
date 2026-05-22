#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
// this check fn checks for intersection points since it starts from origin so it can go [0-k,0+k] then for each Li, Ri..
// we would need the intersection [L-k,R-k]intersection[Li,Ri] -> new L = max(L-k,Li) and new R = min(R-k,Ri) and if at any point L > R .. its false 
bool check(vector<long long> &l, vector<long long> &r, long long x){
    int n = l.size();
    long long L = 0, R = 0;
    for(int i = 0; i<n; i++){
        L = max(l[i],L-x);
        R = min(r[i],R+x);
        if(L>R){
            return false;
        }
    }
    return true;
}
// binary search for k->
int solve(vector<long long> &l,vector<long long> &r){
    long long li = 0, ri = 1e9;
    while(li<ri){
        long long mid = (li+ri)/2;
        if(check(l,r,mid)){
            ri = mid;
        }else{
            li = mid+1;
        }
    }
    return ri;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        vector<long long> l(n);
        vector<long long> r(n);
        for(int i = 0; i<n; i++){
            cin >> l[i] >> r[i];
        }
        long long ans = solve(l,r);
        cout << ans << "\n";
    }
    return 0;
}
