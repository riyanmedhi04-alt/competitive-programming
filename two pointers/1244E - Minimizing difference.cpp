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
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int l = 0, r = n-1;
    while(l<r && k>0){
        long long cnt_l = l+1;
        long long cnt_r = n-r;
        if(cnt_l <= cnt_r){
            long long gap = a[l+1] - a[l];
            long long cost = cnt_l * gap;
            if(k>= cost){
                k -= cost;
                l++;
            }else{
                a[l] += k/cnt_l;
                k = 0;
                break;
            }
        }else{
            long long gap = a[r] - a[r-1];
            long long cost = cnt_r * gap;
            if(k >= cost){
                k -= cost;
                r--;
            }else{
                a[r] -= k/cnt_r;
                k = 0;
                break;
            }
        }
    }
    cout << max(0LL, a[r] - a[l]);
    return 0;
}
