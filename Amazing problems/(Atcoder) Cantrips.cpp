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
    string s;
    cin >> s;
    int r = 0;
    vector<int> pref(n+1, 0);
    for(int i = 0; i<n; i++){
        pref[i+1] = pref[i] + (s[i] == 'o');
    }
    for(int k = 1; k<=n; k++){
        while(r<n && pref[r] == r-k+1){
            r++;
        }
        cout << r << "\n";
    }
    return 0;
}
