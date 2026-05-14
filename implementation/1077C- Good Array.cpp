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
    int n;
    cin >> n;
    // created a maximum and second maximum variables to store the maximum and the second maximum values.
    int maxm = 0, second_maxm = 0;
    vector<int> v(n);
    // sum variable to store sum of the numbers.
    long long sum = 0;
    for(int i = 0; i<n; i++){
        cin >> v[i];
        if(v[i] > maxm){
            second_maxm = maxm;
            maxm = v[i];
        }else if(v[i] > second_maxm){
            second_maxm = v[i];
        }
        sum += v[i];
    }
    vector<long long> ans;
    // for every number other than the maximum, the remaining sum after subtracting it from the sum must be double the maximum of the numbers .
    // for the maximum number , the remaining sum after deleting it must be double of the second maximum of the array of numbers.
    for(int i = 0; i<n; i++){
        if(v[i] != maxm){
            long long x = sum - v[i];
            if(x%2 == 0 && x/2 == maxm){
                ans.push_back(i+1);
            }
        }else{
            long long x = sum - v[i];
            if(x%2 == 0 && x/2 == second_maxm){
                ans.push_back(i+1);
            }
        }
    }
    // printing the number of indexes we stored in the ans array and the indexes itself.
    cout << ans.size() << "\n";
    for(int p : ans){
        cout << p << " ";
    }
    return 0;
    
}
