#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
void dfs(vector<vector<int>> &adj, int node, int parent, int cnt, int m, int &ans, vector<int> &val){
    if(val[node] == 1){
        cnt++;
    }else{
        cnt = 0;
    }
    if(cnt > m){
        return;
    }
    if(node != 1 && adj[node].size() == 1){
        ans++;
        return;
    }
    for(int child : adj[node]){
        if(child == parent){
            continue;
        }
        dfs(adj, child, node, cnt, m, ans, val);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<int> val(n+1);
    for(int i = 1; i<=n; i++){
        int x;
        cin >> x;
        val[i] = x;
    }
    for(int i = 0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 0;
    dfs(adj, 1, -1, 0, m, ans, val);
    cout << ans;
    return 0;
}
