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
    // created a map to store the coordinates as pair in vectors for each element in the matrix->
    map<int,vector<pair<int,int>>> pos;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int x;
            cin >> x;
            pos[x].push_back({i,j});
        }
    }
    // initilize the final answer->
    long long ans = 0;
    for(auto k : pos){
        // for each element in the map we will create a row and column vectors to store their respective coordinates for every position->
        vector<long long> rows;
        vector<long long> cols;
        vector<pair<int,int>> v = k.second;
        // we will initialize prefix sum because look, for each coornate lets say x3 -> since rows is sorted so we will go without abs
        // x3 - x2 + x3 - x1 -> 2*x3 - (x1+x2) -> i*x3 - prefix_sum upto that element. (here i will obviously be 2 since its third element's x coordinate)-> 
        long long prefR = 0, prefC = 0;
        for(auto p : v){
            rows.push_back(p.first);
            cols.push_back(p.second);
        }
        sort(rows.begin(),rows.end());
        sort(cols.begin(),cols.end());
        for(int i = 0; i<rows.size(); i++){
            // storing in ans ->
            ans += 1LL*i*rows[i] - prefR;
            prefR += rows[i];
            ans += 1LL*i*cols[i] - prefC;
            prefC += cols[i];
        }
        
    }
    cout << ans;
    return 0;
}
