#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    long long ans = 0;
    priority_queue<long long> pq;
    for(int i = n-1; i>=0; i-=2){
        pq.push(a[i]);
        pq.push(a[i-1]);
        ans += pq.top();
        pq.pop();
    }
    cout << ans;
    return 0;
}
