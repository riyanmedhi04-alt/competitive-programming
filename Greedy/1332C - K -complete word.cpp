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
    int t;
    cin >> t;
    while(t--){
        int n , k;
        cin >> n >> k;
        string s;
        cin >> s;
        // the first window is of k characters and for a k-complete word we need all k length blocks to be palindrome as it satisfies both the conditions to be a k-complete.
        long long sum = 0;
        // for every base index in k/2 window , we check the max_freq of a characters appearing for each index whose i%k is either base index or k-1-base_idex and sum the total_char - max_freq.
        for(int i = 0; i<=k/2; i++){
            if(i == k/2 && k%2 == 0){
                continue;
            }
            int idx = i;
            map<char,int> m;
            int max_freq = 0, cnt = 0;
            for(int j = i; j<n; j+= k){
                m[s[j]]++;
                cnt++;
                max_freq = max(max_freq, m[s[j]]);
            }
            if(i == k/2){
                sum += cnt - max_freq;
                continue;}
            for(int j = k-1-i; j<n; j+= k){
                m[s[j]]++;
                cnt++;
                max_freq = max(max_freq,m[s[j]]);
            }
            
            sum += cnt - max_freq;
        }
        cout << sum << "\n";
    }
    return 0;

}
