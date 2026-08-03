#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <functional>
using namespace std;
// Buy Low Sell High USING GREEDY !!
// we wll use a min heap to store the options as sorted ad get the smallest element in log(n) time which calculates the total time complexuity to nlogn!!
// treat all the prices as options i can have for future whenever i get a higher price i will sell it but also push the higher price at that time since it acts as a regret mechanism so taht if i ever had a better option i can use that price again
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i<n; i++){
        cin >> p[i];
    }
    // min-heap: smallest element at top

    priority_queue<int, vector<int>, greater<int>> pq; // options i have at each day
    long long profit = 0;
    for(int i = 0; i<n; i++){
        if(i == 0){
            pq.push(p[i]);
        }else{
            int x = pq.top();
            if(x < p[i]){
                profit += p[i] - x;
                pq.pop();
                pq.push(p[i]); // pusehed as a regret mechanism 
            }
            pq.push(p[i]); // pushed as a option 
        }
    }
    cout << profit;
    return 0;

}
