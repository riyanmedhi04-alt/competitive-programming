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
    vector<int> a(n);
    long long sum = 0;
    int mx = 0;
    for(int i = 0; i<n; i++){
        cin >> a[i];
        sum += a[i];
        mx = max(mx,a[i]);
    }
    bool valid = true;
    if(sum%2 != 0){
        valid = false;
    }
    if(valid){
        if(mx <= sum-mx){
            cout << "YES" ;
        }else{
            cout << "NO";
        }
    }else{
        cout << "NO";
    }
    return 0;
}
