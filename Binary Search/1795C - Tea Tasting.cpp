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
        int n;
        cin >> n;
        vector<long long> a(n),b(n);
        // created a prefixB array for storing prefix of b 
        vector<long long> prefixB(n);
        for(int i = 0; i<n; i++){
            cin >> a[i];
        }
        for(int i= 0; i<n; i++){
            cin >> b[i];
            if(i == 0){
                prefixB[i] = b[i];
            }else{
                prefixB[i] = prefixB[i-1] + b[i];
            }
        }
        // lets say we are at day i and the tea here is a[i].. now lets say that we have enough tea ai such that from i , i+1, ... j-1 can completely consume their limits . but at j i.e at bj, the remaining tea isnt enough (only if j<n) for taking all of the limit of bj. rem[j] -> stores exactly that rem tea for jth .
        // pos is the first day where cumulative capacity reaches/exceeds
// the tea amount a[i].
// Days [i, pos-1] consume their full limits.
// If pos < n, then day pos consumes only the remaining tea.
        // cnt here add +1 to every day from i i+1 to j-1 .. i.e those days the tea can have consumed all the person's limit so cnti +1, cnti+1 +1... cntj-1 +1. 
        // how can we find j? use binary seach (lower bound).
        vector<long long> rem(n,0);
        vector<long long> cnt(n+1, 0);
        for(int i = 0; i<n; i++){
            long long before = (i == 0? 0 : prefixB[i-1]);
            long long target = before + a[i];
            int pos = lower_bound(prefixB.begin() , prefixB.end(), target) - prefixB.begin();
            // The trick here is that instead of updating each time the cnt by +1 from i to j-1 .. we can instead cnt[i]++ and cnt[j]-- ... then at the end after computing everything we can just take prefixes for any random cnt[k] to get how many times that kth person used its full limit!
            cnt[i]++;
            cnt[pos]--;
            if(pos<n){
                long long full = 0;
                if(pos > i){
                    full = prefixB[pos-1] - (i? prefixB[i-1] : 0);
                }
                rem[pos] += a[i] -full;
            }
        }
        vector<long long> prefix_full(n);
        for(int i = 0; i<n; i++){
            prefix_full[i] = (i? prefix_full[i-1]+cnt[i]: cnt[i]);
        }
        for(int i = 0; i<n; i++){
            long long ans = rem[i] + prefix_full[i]*b[i];
            cout << ans << " ";
        }
        cout << "\n";

    }
    return 0;
}
