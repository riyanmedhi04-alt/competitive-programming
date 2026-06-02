#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
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
        vector<long long> u(n), s(n);
        unordered_map<int, vector<long long>> m;
        for(int i = 0; i<n; i++){
            cin >> u[i];
        }
        for(int i = 0; i<n; i++){
            long long x;
            cin >> x;
            m[u[i]].push_back(x);
        }
        unordered_map<int, long long> sums;
        unordered_map<int, vector<long long>> sufix;
        for(auto a : m){
            vector<long long> v = a.second;
            sort(v.rbegin(), v.rend());
            long long sum = 0;
            for(int i = v.size() -1; i>=0; i--){
                sum += v[i];
                sufix[a.first].push_back(sum);
            }
            sums[a.first] = sum;
        }
        vector<long long> ans(n+1, 0);
        for(auto x : m){
            int sz = m[x.first].size();
            for(int k = 1; k<=sz; k++){
                int rem = sz%k;
                if(rem == 0){
                    ans[k] += sums[x.first];
                }else{
                    ans[k] += sums[x.first] - sufix[x.first][rem-1];
                }
            } 
        }
        for(int k = 1; k<=n; k++){
            cout << ans[k] << " ";
        }
        cout << "\n";
    }
    return 0;
}
