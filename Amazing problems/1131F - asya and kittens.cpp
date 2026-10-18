#include <iostream>
#include <vector>
using namespace std;

const long long N = 300005;

vector<long long> parent(N);
vector<vector<long long>> tree(N);

long long find(long long x){
    if(parent[x] == x){
        return x;
    }
    parent[x] = find(parent[x]);
    return parent[x];
}

void unite(long long x, long long y, long long &cnt){
    long long x_ref = find(x);
    long long y_ref = find(y);

    if(x_ref == y_ref){
        return;
    }

    cnt++;
    long long newNode = cnt;

    tree[newNode].push_back(x_ref);
    tree[newNode].push_back(y_ref);

    parent[x_ref] = newNode;
    parent[y_ref] = newNode;
    parent[newNode] = newNode;
}

void dfs(long long root, vector<long long> &res, long long n){
    if(root <= n){
        res.push_back(root);
        return;
    }

    for(long long u : tree[root]){
        dfs(u, res, n);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;

    long long cnt = n;

    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    for(int i = 0; i < n-1; i++){
        long long x, y;
        cin >> x >> y;
        unite(x, y, cnt);
    }

    vector<long long> res;

    long long root = find(1);
    dfs(root, res, n);

    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }

    return 0;
}
