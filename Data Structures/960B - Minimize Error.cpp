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
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    int k = k1 + k2;
    vector<int> a(n), b(n);
    // using priority queue!!
    priority_queue<long long> pq;
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    for(int i = 0; i<n; i++){
        cin >> b[i];
    }
    for(int i = 0; i<n; i++){
        long long diff = abs(a[i] - b[i]);
        pq.push(diff);
    }
    for(int i = 0; i<k; i++){
        long long diff = pq.top();
        pq.pop();
        if(diff > 0){
            diff--;
        }else{
            diff++;
        }
        pq.push(diff);
    }
    long long E = 0;
    while(!pq.empty()){
        long long diff = pq.top();
        E += diff*diff;
        pq.pop();
    }
    cout << E;
    return 0;
}
