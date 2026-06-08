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
    cin>> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> a(n), prefix(n);
        for(int i = 0; i<n; i++){
            cin >> a[i];
            if(i == 0){
                prefix[i] = a[i];
            }else{
                prefix[i] = prefix[i-1] + a[i];
            }
        }
        sort(a.begin(), a.end());
        int l = 0, r = n-1;
        long long x = 0, cnt = 0, p = 0;
        while(l<r){
            if(x+a[l] < a[r]){
                cnt += a[l];
                x += a[l];
                l++;
            }else if(x+a[l]>a[r]){
                a[l] -= a[r] -x;
                cnt += a[r] - x;
                cnt++;
                x = 0;
                r--;
            }else{
                cnt += a[l];
                cnt++;
                x = 0;
                l++;
                r--;
            }
        }
        if(l == r){
            long long e = a[l];
            if(x > e){
                cnt += e;
            }else if(x == e){
                cnt++;
            }else{
                if(e == 1){
                    cnt++;
                }else{
                long long k = (e-x)/2;
                cnt += k;
                e -= k;
                x += k;
                cnt += (e+x-1)/x;
                }
            }
        }
        
        cout << cnt << "\n";
    }
    return 0;

}
