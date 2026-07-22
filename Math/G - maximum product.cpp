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
    long long a, b;
    cin >> a >> b;
    long long temp1 = a, temp2 = b;
    long long cand1 = 1, cand2 = 1, cand3 = 1;
    bool flag = false;
    int x = 0, y= 0, y1 = 0;
    int sz_a = 0, sz_b = 0;
    string s = to_string(b);
    sz_b = s.size();
    string s_a = to_string(a);
    sz_a = s_a.size();
    long long prod = 1, mx = 1;
    string ans = "";
    ans = s;
    for(char ch : s){
        mx *= ch- '0';
    }
    for(int i = 0; i<sz_b; i++){
        int d = s[i] - '0';
        string can = "";
        if(i == 0 && d == 1){
            long long x = 1;
            for(int j = 1; j<sz_b; j++){
                can += '9';
                x *= 9;
            }
            if(can.empty()){
                prod *= d;
                continue;
            }
            long long num = stoll(can);
            if(num >= a && x>mx){
                mx = x;
                ans = can;
            }
            prod *= d;
            continue;
        }
        if(d == 0){
            prod *= d;
            continue;
        }
        long long x = prod;
        for(int j = 0; j<i; j++){
            can += s[j];
        }
        x *= d-1;
        if(d-1 > 0){
            can += char('0' + d-1);
        } 
        for(int j = i+1; j<sz_b;j++){
            x*=9;
            can += '9';
        }   
        long long num = stoll(can);
        if(num >= a && x>mx){
            mx = x;
            ans = can;
        }    
        prod *= d;
    }
    cout << ans;
    return 0;
}
