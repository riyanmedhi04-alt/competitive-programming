#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
bool isPalindrome(string &s, int start, int end){
    int l = start, r = end;
    int cnt = 0;
    while(l<r){
        if(s[l] == s[r]){
            r--;
            l++;
        }else{
            cnt++;
            l++;
            r--;
        }
    }
    if(cnt<=1){
        return true;
    }else{
        return false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int cnt = 0;
    int n = s.size();
    int bad = 0;
    for(int i = 0; i<n; i++){
        int l = i;
        int r = i;
        // checking odd length subarrays expanding from centre
        int cnt = 0;
        while(l>=0 && r<n){
            if(s[l] != s[r]){
                cnt++;
            }
            if(cnt>1){
                bad++;
            }
            l--;
            r++;
        }
        //checking even length subarrays expanding from the centre
        cnt = 0;
        l = i;
        r = i+1;
        while(l>= 0 && r<n){
            if(s[l] != s[r]){
                cnt++;
            }
            if(cnt>1){
                bad++;
            }
            l--;
            r++;
        }
    }
    long long total = n*(n+1)/2;
    cout << total - bad;
    return 0;
}
