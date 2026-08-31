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
        long long n;
        cin >> n;
        vector<long long> a(n);
        bool has_odd = false, has_even = false;
        for(int i = 0; i<n; i++){
            cin >> a[i];
            if(a[i]%2 != 0){
                has_odd = true;
            }else{
                has_even = true;
            }
        }
        if(has_even && has_odd){
            cout << -1 << "\n";
            continue;
        }
        vector<long long> ops;
        for(int i = 29; i>=0; i--){
            ops.push_back((1LL<<i));
        }
        if(has_even){
            ops.push_back(1);
        }
        cout << ops.size() << "\n";
        for(long long x : ops){
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
