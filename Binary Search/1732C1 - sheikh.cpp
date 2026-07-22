#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
// main hint is -> f(l,r) <= f(l, r+1) !!
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<int> a(n+1), non_zero_indices;
        for(int i = 1; i<=n; i++){
            cin >> a[i];
            if(a[i] > 0){
                non_zero_indices.push_back(i);
            }
        }
        vector<long long> prefix_sum(n+1,0);
        vector<long long> prefix_xor(n+1,0);
        for(int i = 1; i<=n; i++){
            prefix_sum[i] = prefix_sum[i-1] + a[i];
            prefix_xor[i] = prefix_xor[i-1] ^ a[i];
        }
       while(q--){
        int l, r;
        cin >> l >> r;
        long long max_f = prefix_sum[r] - prefix_sum[l-1] - (prefix_xor[r] ^ prefix_xor[l-1]);
        if(max_f == 0){
            cout << l << " " << l << "\n";
            continue;
        }
        int best_l = l, best_r = r;
        int min_len = r-l+1;
        for(int right = l; right<=r; right++){
            long long f = prefix_sum[right] - prefix_sum[l-1] - (prefix_xor[right] ^ prefix_xor[l-1]);
            if(f < max_f){
                continue;
            }
            int low = l, high = right, opt_l = l;
            while(low<=high){
                int mid = low + (high - low)/2;
                long long f_mid = prefix_sum[right] - prefix_sum[mid - 1] - (prefix_xor[right] ^ prefix_xor[mid - 1]);
                if(f_mid == max_f){
                    opt_l = mid;
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
            int len = right - opt_l +1;
            if(len < min_len){
                min_len = len;
                best_l = opt_l;
                best_r = right;
            }
        }
        cout << best_l << " " << best_r << "\n";
       }
    }
    return 0;
}
