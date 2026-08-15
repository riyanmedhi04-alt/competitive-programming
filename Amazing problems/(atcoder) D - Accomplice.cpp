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
    long long n, d;
    cin >> n >> d;
    long long mx = 1e6 +1; // maximum range for x !! 
    vector<long long> diff(mx+5); // difference array created to track how many suspects are in the scene at a pount of time!
    for(int i = 0; i<n; i++){
        long long s, t;
        cin >> s >> t;
        long long L = s;
        long long R = t-d; // x+d <= t and x>=s
        if(L<=R){
            diff[L] += 1;
            diff[R+1] += -1;
        }
    }
    long long curr = 0, combinations = 0;
    for(int x = 0; x<=mx; x++){
        curr += diff[x];
        combinations += (curr*(curr - 1))/2;

    }
    cout << combinations;
    return 0;
}
