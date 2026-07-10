#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
// this question uses the concept of RE-ROOTING!!
// here we are using two dfs for filling the dp and ans vector 
// in dfs1 -> basically we are filling the dp for all the subtrees of a particular node where we try to maximize the white nodes to maximize cntW - cntB... it is basically a downward search of filling the dp
// in dfs2 -> here we fill ans vector which is the final answers , for each node we basically have to consider it as a root from where a full grown tree is coming , now the answer for each node will be (the dp filled in its downward search + the maximized whites in its upward tree which can be found out recursively through the help of its parent node!)
void dfs1(vector<vector<int>> &adj, vector<int> &color, vector<int> &dp, int node , int parent){
    for(int child : adj[node]){
        if(child == parent){
            continue;
        }
        dfs1(adj, color, dp,child,node);
        if(dp[child] > 0){
            dp[node] += dp[child];
        }
    }
    dp[node] += (color[node] == 1) ? 1:-1;
}
void dfs2(vector<vector<int>> &adj, vector<int> &dp, vector<int> &ans, int node , int parent){
    for(int child : adj[node]){
        if(child == parent){
            continue;
        }
        int partial = ans[node] - max(0,dp[child]);
        ans[child] = dp[child] + max(0,partial);
        dfs2(adj,dp,ans,child,node);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> color(n+1);
    for(int i = 1; i<=n; i++){
        cin >> color[i];
    }
    vector<vector<int>> adj(n+1);
    for(int i = 0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dp(n+1);
    vector<int> ans(n+1);
    dfs1(adj,color,dp,1,-1);
    ans[1] = dp[1];
    dfs2(adj,dp,ans,1,-1);
    for(int i = 1; i<=n; i++){
        cout << ans[i] << " ";
    }
    return 0;
}
