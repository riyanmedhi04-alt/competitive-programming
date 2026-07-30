#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
int gcd(int a, int b){
    if (b == 0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}
// so the first thing -> if val1 = m*q1 + rem and val2 = m*q2 + rem 
// val1 - val2 is divisible by m so we would find all the differences abs(a[i] - a[i+k]) for a k window then take their gcd since gcd is the m!! (if gcd  not equal to 1 then points++) 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i<n; i++){
            cin >> a[i];
        }
        vector<int> k;
        for(int d = 1; d*d<=n; d++){
            if(n%d == 0){
                k.push_back(d);
                if(n/d != d){
                    k.push_back(n/d);
                }
            }
        }
        int points = 0;
        for(int j = 0; j<k.size(); j++){
            int win = k[j];
            int g = -1;
            for(int i = 0; i<=n-1-win; i++){
                int diff = abs(a[i] - a[i+win]);
                if(i == 0){
                    g = diff;
                }else{
                    g = gcd(diff, g);
                }
            }
            if(g == 1){
                continue;
            }else{
                points++;
            }
        }
        cout << points << "\n";
    }
    return 0;
}
