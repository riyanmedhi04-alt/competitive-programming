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
        // create three variables storing number of 0,1,2.
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for(int i = 0; i<n; i++){
            int x;
            cin >> x;
            if(x == 0){
                cnt0++;
            }else if(x == 1){
                cnt1++;
            }else{
                cnt2++;
            }
        }
        long long ans = 0;
        // individual 0's contribute to ans .
        ans += cnt0;
        // min of 1 and 2 contributes as 1 + 2 = 3, so they could become individual subsequences.
        ans += min(cnt1, cnt2);
        // also the left 1's OR 2's make subsequence of 1+1+1 or 2+2+2 hence contributes...if they are available in enough amounts i.e min 3.
        ans += (cnt1 + cnt2 - 2*min(cnt1,cnt2))/3;
        cout << ans << "\n";
    }
    return 0;
    
}
