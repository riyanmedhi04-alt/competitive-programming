#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
bool check(long long target, vector<long long> &a, int k, int n){
    for(int i = 0; i<n; i++){
        long long curr = target;
        long long cost = 0;
        // if we need a1 -> x then a2 has to be atleats x-1 , a3 -> x-2 .. and so on till we reach a ai > x-i!!
        for(int j = i; j<n; j++){
            if(a[j] >= curr){
                if(cost <= k){
                    return true;
                }else{
                    break;
                }
            }
            if(j == n-1){
                break;
            }
            cost += curr - a[j];
            curr--;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<long long> a(n);
        long long mn = INT_MAX, mx = INT_MIN;
        for(int i = 0; i<n; i++){
            cin >> a[i];
            mx = max(mx, a[i]);
       }
        long long x_min = 1, x_max = mx + k;
        // binary search on range [x_min, x_max] ->
        long long l = x_min, r = x_max;
        long long ans = -1;
        while(l<=r){
            long long target = l + (r-l)/2;
            if(check(target,a,k,n)){
                ans = target;
                l = target +1;
            }else{
                r = target -1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
