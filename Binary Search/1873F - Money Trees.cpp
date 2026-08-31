#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
bool get(int dist, vector<long long> &len, int k, int n, vector<long long> &pref){
    bool found = false;
    for(int i = 0; i<n-dist+1; i++){
        if(len[i] < dist){
            continue;
        }
        int sum = pref[i+dist] - pref[i];
        if(sum <= k){
            found = true;
            break;
        }
    }
    return found;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long n, k;
        cin >> n >> k;
        vector<long long> a(n), h(n);
        for(int i = 0 ;i<n; i++){
            cin >> a[i];
        }
        for(int i = 0; i<n ;i++){
            cin >> h[i];
        }
        vector<long long> pref(n+1);
        pref[0] = 0;
        for(int i = 0; i<n; i++){
            pref[i+1] = pref[i] + a[i];
        }
        vector<long long> len(n);
        len[n-1] = 1;
        for(int i = n-2; i>=0; i--){
            if(h[i]%h[i+1] == 0){
                len[i] = len[i+1] +1;
            }else{
                len[i] = 1;
            }
        }
        int l = 1, r = n;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(get(mid, len, k, n, pref)){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        cout << r << "\n";
    }
    return 0;
}
