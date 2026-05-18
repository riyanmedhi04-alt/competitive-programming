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
        long long n, w;
        cin >> n >> w;
        vector<long long> v;
        // created a freq map to store the freq of the particular weight class of box.
        map<long long, long long> freq;
        // and a set to use to store only the unique values of boxes to vector v.
        set<long long> s;
        for(int i = 0; i<n; i++){
            long long x;
            cin >> x;
            freq[x]++;
            if(s.find(x) == s.end()){
                v.push_back(x);
            }
            s.insert(x);
        }
        // sort in reverse order.
        sort(v.begin(),v.end(), greater<long long>());
        long long total = n;
        long long height = 0;
        // while loop does one iteration for every height level.
        while(total > 0){
            long long rem = w;
            // these loops for laying out boxes in order of largest -> smallest so that we fill each row or height level by largest first to be optimal.
            for(int i = 0; i<v.size(); i++){
                while(freq[v[i]] > 0 && v[i]<=rem){
                    freq[v[i]]--;
                    rem -= v[i];
                    total--;
                }
            }
            // height increases by one after every iteration.
            height++;
        }
        cout << height << "\n";

    }
    return 0;
    
}
