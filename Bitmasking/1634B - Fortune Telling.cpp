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
        long long n, x, y;
        cin >> n >> x >> y;
        // we will only check for alice , if she wins bob loses and vice versa.
        // we will only check the parity of answer that is the final ans will be odd or even as for eg ->if ans is even and y is also even than it must be the answer as both (+) & (^) gives same parity if a[i] is even and changes the parity if its odd.
        long long parity = x&1;
        // if parity -> 0 : even else odd.
        // lets check only for one operation i.e + or ^ as both have same nature for both parities.
        for(int i = 0; i<n; i++){
            long long a;
            cin >> a;
            parity ^= a;
        }
        if((parity & 1) == (y & 1)){
            cout << "Alice" << "\n";
        }else{
            cout << "Bob" << "\n";
        }
    }
    return 0;

}
