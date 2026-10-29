#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
const long long N = 2e5 + 7;
vector<long long> parent(N);
vector<long long> specialCount(N,0);
long long find(long long x){
    if(parent[x] == x){
        return x;
    }
    parent[x] = find(parent[x]);
    return parent[x];
}
void unite(long long x, long long y){
    long long x_ref = find(x);
    long long y_ref = find(y);
    if(x_ref == y_ref){
        return;
    }
    parent[y_ref] = x_ref;
    specialCount[x_ref] += specialCount[y_ref];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i<=n; i++){
        parent[i] = i;
    }
    vector<long long> special(k);
    for(int i = 0; i<k; i++){
        cin >> special[i];
        specialCount[special[i]] = 1;
    }
    vector<pair<long long, pair<long long, long long>>> weights;
    while(m--){
        long long u, v, w;
        cin >> u >> v >> w;
        weights.push_back({w, {u,v}});
    }
    sort(weights.begin(), weights.end());
    long long mx = 0;
    for(int i = 0; i<weights.size(); i++){
        long long w = weights[i].first;
        long long u = weights[i].second.first;
        long long v = weights[i].second.second;
        mx = max(mx, w);
        unite(u,v);
        if(specialCount[find(u)] == k){
            break;
        }
    }
    for(int i = 0; i<k; i++){
        cout << mx << " ";
    }
    return 0;
}
