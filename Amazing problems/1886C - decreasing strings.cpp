#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        long long pos;
        cin >> pos;
        string ans = "";
        long long n = s.size();
        long long curr_len = n;
        long long k = 0;
        while(pos > curr_len){
            pos -= curr_len;
            curr_len--;
            k++;
        }
        for(int i = 0; i<n; i++){
            char ch = s[i];
            while(!ans.empty() && k>0 && ans.back() > ch){
                ans.pop_back();
                k--;
            }
            ans.push_back(ch);
        }
        while(k>0){
            ans.pop_back();
            k--;
        }
        cout << ans[pos-1];
    }
    return 0;
}
