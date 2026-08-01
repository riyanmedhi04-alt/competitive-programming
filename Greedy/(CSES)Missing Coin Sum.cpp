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
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    long long v = 0;
    for(int i = 0; i<n; i++){
        if(a[i] > v+1){
            break;
        }else{
            v += a[i];
        }
    }
    cout << v+1;
    return 0;
}
