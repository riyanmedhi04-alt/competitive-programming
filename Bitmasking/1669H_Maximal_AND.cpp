#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long n, k;
        cin >> n >> k;
        vector<long long> v(n);
        long long ans;
        // here first we constructed the AND of all the elements in the array.
        for(int i = 0; i<n; i++){
            cin >> v[i];
            if(i == 0){
                ans = v[0];
            }else{
                ans &= v[i];
            }
        }
        // then we checked bit by bit from HIGH -> LOW for each element in the aray whether its a set Bit or unset Bit.
        // and counted the nos of set bit.
        for(int bit = 30; bit>=0; bit--){
            int cnt_setBit = 0;
            for(int i = 0; i<n; i++){
                if(v[i] & (1LL<<bit)){
                    cnt_setBit++;
                }
            }
            // stored the nos of unsetBits.
            int need = n - cnt_setBit;
            if(need <= k){
                // modified AND of the elements of the array if the nos of unsetBit is less than or equal to K.
                // since the order of bits are iterating from HIGH -> LOW hence we get the MAX of AND of elements everytime.
                // Then we also modified k by deleting the operations we used.
                ans |= (1LL<<bit);
                k -= need;
            }
        }
        cout << ans << "\n";
    }
    return 0;
    
}
