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
        long long a, b, r;
        cin >> a >> b >> r;
        long long limit = abs(a-b);
        if(limit == 0){
            cout << limit << "\n";
            continue;
        }
        long long mx = max(a,b);
        long long mn = min(a,b);
        long long a1 = mx;
        long long b1 = mn;
        int first = -1;
        long long x = 0;
        for(int bit = 62; bit>=0; bit--){
            if(first == -1 && (a1 & (1LL << bit)) != (b1 & (1LL << bit))){
                first = bit;
            }else if(first != -1){
                if((a1 & (1LL << bit)) != 0  && (b1 & (1LL << bit)) == 0){
                    if((x + (1LL << bit)) <= r){
                        x |= (1LL << bit);
                    }
                }
            }
        }
        cout << (a1 ^ x) - (b1 ^ x) << "\n";
    }
    return 0;
}
