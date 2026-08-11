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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n-1), c(n), d(n);
    for(int i = 0; i<n; i++){
        cin >> a[i];
        c[i] = a[i];
        d[i] = a[i];
    }
    for(int i = 0; i<n-1; i++){
        cin >> b[i];
    }
    int cnt1 = 0, cnt2 = 0;

    c[0] = 0;
    if(a[0] == 1){
        cnt1++;
    }
    for(int i = 1; i<n; i++){
        if((c[i] + c[i-1])%m != b[i-1]){
            c[i] += 1;
            cnt1++;
        }
    } 
    d[0] = 1;
    if(a[0] == 0){
        cnt2++;
    }
    for(int i = 1; i<n; i++){
        if((d[i] + d[i-1])%m != b[i-1]){
            d[i] += 1;
            cnt2++;
        }
    }
    cout << min(cnt1,cnt2);
    return 0;
}
