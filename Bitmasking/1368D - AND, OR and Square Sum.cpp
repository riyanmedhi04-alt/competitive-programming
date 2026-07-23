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
    int n;
    cin >> n;
    vector<long long> a(n);
    long long Or = 0;
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    if(n == 1){
        cout << a[0] * a[0];
        return 0;
    }
    vector<int> cnt1(20);
    for(int i = 0; i<n; i++){
        for(int bit = 0; bit<20; bit++){
            if(a[i] & (1<<bit)){
                cnt1[bit]++;
            }
        }
    }
    vector<long long> v(n,0);
    for(int i = 0; i<n; i++){
        for(int bit = 0; bit<20; bit++){
            if(cnt1[bit] >0){
                v[i] |= (1LL << bit);
                cnt1[bit]--;
            }
        }
    }
    long long ans = 0;
    for(int i = 0; i<n; i++){
        ans += v[i]*v[i];
    }
    cout << ans;
    return 0;
}
