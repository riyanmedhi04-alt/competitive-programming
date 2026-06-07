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
        int n, k, p , m;
        cin >> n >> k >> p >> m;
        vector<int> v(n);
        for(int i = 0; i<n; i++){
            cin >> v[i];
        }
        int idx = p-1;
        int cnt = 0;
        if(idx>= 0 && idx<=k-1){
            if(m<v[idx]){
                cout << 0 << "\n";
                continue;
            }
            m -= v[idx];
            cnt++;
            v.push_back(v[idx]);
            v.erase(v.begin() + idx);
            idx = n-1;
        }else{
            sort(v.begin(), v.begin() +idx);
            int r = idx - (k-1);
            int add = 0;
            for(int i = 0; i<r; i++){
                add += v[i];
            }
            add += v[idx];
            if(m < add){
                cout << 0 << "\n";
                continue;
            }
            cnt++;
            m -= add;
            v.push_back(v[idx]);
            v.erase(v.begin() + idx);
            idx = n-1;
        }
        sort(v.begin(), v.begin() +idx);
        int range = idx - (k-1);
        int sum = 0;
        for(int i = 0; i<range; i++){
            sum += v[i];
        }
        int cycle = sum + v[idx];
        cnt += m/cycle;
        cout << cnt << "\n";
        
    }
    return 0;
}
