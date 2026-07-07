#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
// THIS PROBLEM INTRODUCES A IMP CONCEPT OF TREE DIAMETER!!
void dfs(vector<vector<int>> &adj, int node, int parent, vector<long long> &dist1, int k, long long dist){
    dist1[node] = dist;
    for(int child : adj[node]){
        if(child == parent){
            continue;
        }
        dfs(adj, child, node, dist1, k, dist+1);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long n, k, c;
        cin >> n >> k >> c;
        vector<vector<int>> adj(n+1);
        for(int i = 0; i<n-1; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // Step 1 : we will dfs from vertex 1 to find distances to all the nodes and also mark the maximum distance from it to be node A.
        vector<long long> dist1(n+1); // this vector will store the distances from vertex 1 to nodes!!
        dfs(adj, 1,-1,dist1,k,0);
        // lets find nodeA
        int nodeA = -1;
        long long maxm = -1;
        for(int i = 1; i<=n; i++){
            if(dist1[i] > maxm){
                maxm = dist1[i];
                nodeA = i;
            }
        }
        // Step 2 : dfs again from nodeA to find the maximum distanced node from it (calling it nodeB) and also store all the distances from it in a vector 
        vector<long long> distA(n+1);
        dfs(adj,nodeA,-1,distA,k,0);
        //lets find nodeB
        int nodeB = -1;
        maxm = -1;
        for(int i = 1; i<=n; i++){
            if(distA[i] > maxm){
                maxm = distA[i];
                nodeB = i;
            }
        }
        // Step 3: dfs again from nodeB and store all distances 
        vector<long long> distB(n+1);
        dfs(adj,nodeB,-1,distB,k,0);
        // Step 4: the core idea here is that for any node theres only two extremes left edge and right edge that are nodeA and nodeB and we only need the distnace from that ndoe which is more bigger i.e its distance till nodeA or nodeB !! (TREE DIAMETER MAGIC)
        long long max_profit = 0;
        for(int i = 1; i<=n; i++){
            long long max_dist = max(distA[i],distB[i]);
            long long curr_profit = (max_dist*k) - (dist1[i]*c);
            max_profit = max(max_profit,curr_profit);
        }
        cout << max_profit << "\n";
    }
    return 0;
}
