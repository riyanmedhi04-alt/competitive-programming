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
        int n;
        cin >> n;
        vector<int> a, b;
        for(int i = 0; i<n; i++){
            int x, y;
            cin >> x >> y;
            a.push_back(x);
            b.push_back(y);
        }
        int n1 = a.size();
        int n2 = b.size();
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        long long cx, cy;
        if(n1%2 == 0){
            int mid1 = (n1-1)/2;
            int mid2 = (n1)/2;
            cx = a[mid2] - a[mid1] +1;
        }else{
            cx = 1;
        }
        if(n2%2 == 0){
            int mid1 = (n2-1)/2;
            int mid2 = (n2)/2;
            cy = b[mid2] - b[mid1] +1;
        }else{
            cy = 1;
        }
        long long ans = cx*cy;
        cout << ans << "\n";
    }
    return 0;
}
