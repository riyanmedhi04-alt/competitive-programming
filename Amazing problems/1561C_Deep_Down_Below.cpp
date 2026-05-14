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
    cin >>t;
    while(t--){
        int n;
        cin >> n;
        // created a vector to store the min power to required to defeat all the monsters in taht particular cave and the power power gained after clearing the entire cave which is nothing but the size of the cave.
        vector<pair<int,int>> caves;
        for(int j = 0; j<n; j++){
            int need = 0;
            int k;
            cin >> k;
            for(int i = 0; i<k; i++){
                int x;
                cin >> x;
                need = max(need, x - i +1);
            }
            caves.push_back({need,k});
        }
        // sorted the cave wrt to the min power required to clear the entire cave.
        sort(caves.begin(),caves.end());
        long long ans = 0;
        long long killed = 0;
        for(auto cave : caves){
            // for each cave store the ans to be the max of the ans and the min_power req minus the monsters killed.
            ans = max(ans, 1LL* cave.first - killed);
            killed += cave.second;
        }
        cout << ans << "\n";
    
    }
    return 0;
    
}
