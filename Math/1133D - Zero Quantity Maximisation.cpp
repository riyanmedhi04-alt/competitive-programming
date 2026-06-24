#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a%b);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    for(int i = 0; i<n; i++){
        cin >> b[i];
    }
    // here we will map the pairs as per the division of a[i] & b[i] by their gcd as iw will give us the actual division like the root items !! ***
    map<pair<int,int>,int> m;
    int universal_matches = 0;
    int max_freq = 0;
    for(int i = 0; i<n; i++){
        if(a[i] == 0){
            if(b[i] == 0){
                universal_matches++;
            }
            continue;
        }
        int num = -b[i];
        int den = a[i];
        int g = gcd(num,den);
        num /= g;
        den /= g;
        if(den < 0){
            num = -num;
            den = -den;
        }
        m[{num,den}]++;
        max_freq = max(max_freq, m[{num,den}]);
    }
    int ans = max_freq + universal_matches;
    cout << ans;
    return 0;
}
