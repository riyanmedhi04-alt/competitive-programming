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
    vector<int> a(n+2);
    a[0] = 0;
    a[n+1] = n+1;
    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }
    vector<pair<int,int>> v;
    vector<int> idx(n+2), pos(n+2);
    for(int i = 0; i<n+2; i++){
        v.push_back({a[i],i});
    }
    sort(v.begin(),v.end());
    vector<int> p;
    for(int i = 0; i<n+2; i++){
        p.push_back(v[i].second);
    }
    int rounds = 1;
    for(int i = 1; i<=n; i++){
        if(v[i].second < v[i-1].second){
            rounds++;
        }
    }
    for(int i = 0; i<n+2; i++){
        idx[i] = p[i];
        pos[p[i]] = i;
    }
    for(int i = 0; i<m; i++){
        int a, b;
        cin >> a >> b;
        int idx1 = max(pos[a],pos[b]);
        int idx2 = min(pos[a],pos[b]);
        if(idx[idx2-1] > idx[idx2]){
            rounds--;
        }
        if(idx1-idx2 == 1){
            if(idx[idx1] < idx[idx2]){
                rounds--;
            }
        }else{
            if(idx[idx1-1] > idx[idx1]){
                rounds--;
            }
            if(idx[idx2+1] < idx[idx2]){
                rounds--;
            }
        }
        if(idx[idx1+1] < idx[idx1]){
            rounds--;
        }
        int j = idx[idx1];
        int u = idx[idx2];
        idx[idx1] = u;
        pos[u] = idx1;
        idx[idx2] = j;
        pos[j] = idx2;
        if(idx[idx2-1] > idx[idx2]){
            rounds++;
        }
        if(idx1-idx2 == 1){
            if(idx[idx1] < idx[idx2]){
                rounds++;
            }
        }else{
            if(idx[idx1-1] > idx[idx1]){
                rounds++;
            }
            if(idx[idx2+1] < idx[idx2]){
                rounds++;
            }
        }
        if(idx[idx1+1] < idx[idx1]){
            rounds++;
        }
        cout << rounds << "\n";
    }
    return 0;
}
