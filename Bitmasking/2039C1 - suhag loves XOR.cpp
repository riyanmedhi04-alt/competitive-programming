#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
long long  gcd(long long a, long long b){
    if (b == 0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long x, m;
        cin >> x >> m;
        long long ans = 0;
      // we will take min of 2*x and m as id d is a divisor of t and d<t then we know d<[t/2]!!
        for(int r = 1; r<= min(2LL*x, m); r++){
            if(x == r){continue;}
            long long d = x^r;
            if(x%d == 0 || r%d == 0){
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
