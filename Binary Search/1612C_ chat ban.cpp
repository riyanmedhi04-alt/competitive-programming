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
        long long k , x;
        cin >> k >> x;
        // stored values of maximum emotes possible and maximum chats in a emote in two variables.
        long long maxm_emotes = 2*k - 1;
        long long maxm_chats = (maxm_emotes +1)/2;
        long long l = 1, r = maxm_emotes;
        // calculated the tota sum of all the chats.
        long long p = maxm_chats - 1;
        long long total = (p*(p+1)) + maxm_chats;
        // set the final ans to the maximum emotes possible.
        long long ans = maxm_emotes;
        // binary search on finding the ans.
        while(l<=r){
            long long mid = (l+r)/2;
            if(mid <= k){
                // for sum of ascending values.
                long long sum = (mid* (mid+1))/2;
                if(sum >= x){
                    ans = mid;
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }else{
                // for sum of descending values.
                long long e = maxm_emotes - mid;
                long long sum = total - (e*(e+1))/2;
                if(sum>= x){
                    ans = mid;
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
    
}
