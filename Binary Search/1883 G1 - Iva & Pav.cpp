#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
// this is a check fn to check if in that range [l,r] wheather that bit is present and if present then we add it to the value we are creating. if the value is >= k, then its true->
bool check(long long l, long long r, long long k, vector<vector<long long>> &prefix){
    long long val = 0;
    long long len = r-l+1;
    for(int bit = 0; bit<32; bit++){
        int cnt = prefix[bit][r] - prefix[bit][l-1];
        if(cnt == len){
            val |= (1LL << bit);
        }
    }
    return val >= k;
}
// Since AND decreases monotonically as r increases:
// valid → valid → valid → invalid → invalid
// This screams:
// Binary Search on r

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        vector<long long> v(n);
        for(int i = 0; i<n; i++){
            cin >> v[i];
        }
        // we will create a prefix[bit][i] for storing if that element has on bit.
        vector<vector<long long>> prefix(32,vector<long long>(n+1, 0));
        for(int i = 0; i<32; i++){
            for(int j = 1; j<=n; j++){
                prefix[i][j] = prefix[i][j-1];
                if(v[j-1] & (1LL<<i)){
                    prefix[i][j]++;
                }
            }
        }
        int q;
        cin >> q;
        for(int i = 0; i<q; i++){
            long long l, k;
            cin >> l >> k;
            int low = l, high = n;
            int ans = -1;
            // binary search for maximum q->
            while(low<=high){
                int mid = (low+high)/2;
                if(check(l,mid,k,prefix)){
                    ans = mid;
                    low = mid+1;
                }else{
                    high = mid - 1;
                }
            }
            cout << ans << " ";
        }
        cout << "\n";
    }
    return 0;
}
