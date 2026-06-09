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
        vector<long long> a(n);
        long long xor0 = 0, xor1 = 0;
        for(int i = 0; i<n; i++){
            cin >> a[i];
        }
        string s;
        cin >> s;
        // first store the xors of '1' and '2'
        for(int i = 0; i<n; i++){
            if(s[i] == '1'){
                xor1 ^= a[i];
            }else{
                xor0 ^= a[i];
            }
        }
        // create a prefix array of xors
        vector<long long> prefix(n);
        for(int i = 0; i<n; i++){
            if(i == 0){
                prefix[0] = a[i];
                continue;
            }
            prefix[i] = prefix[i-1] ^ a[i] ;
        }
        int q;
        cin >> q;
        // val variable is initialized so that whenever flip happens in the first query we can just accumulate val in xor1 or xor0
        long long val = 0;
        while(q--){
            int x;
            cin >> x;
            if(x == 1){
                int l, r;
                cin >> l >> r;
                val = prefix[r-1] ^ prefix[l-1] ^ a[l-1];
                // lets take [1 2 3 4] ... l = 1(0 indexed) and r = 3. val = 2^3^4 ... let xor0 = 1^3 and xor1 = 2^4 ... then obviously the same elements will cancel in xor so it wont be aproblem when flipped
                // val ^ xor0 = 1^3^2^3^4  = 1^2^4 and xor1 = 2^4^2^4^3 = 3
                xor0 ^= val;
                xor1 ^= val;
            }else{
                int g;
                cin >> g;
                if(g == 0){
                    cout << xor0 << " ";
                }else{
                    cout << xor1 << " ";
                }
            }
        }
        cout << "\n";
    }
    return 0;
}
