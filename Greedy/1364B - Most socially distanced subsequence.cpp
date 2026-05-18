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
        vector<int> v(n);
        vector<int> ans;
        for(int i = 0; i<n; i++){
            cin >> v[i];
        }
        // idea is to count the local extremes with including the first and last element. by intuition ->
        for(int i = 0; i<n; i++){
            if(i == 0 || i == n-1){
                ans.push_back(v[i]);
                continue;
            }
            if((v[i] < v[i-1] && v[i] < v[i+1]) || (v[i] > v[i-1] && v[i] > v[i+1])){
                ans.push_back(v[i]);
            }
        }
        cout << ans.size() << "\n";
        for(int i = 0; i<ans.size() ; i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;

}
