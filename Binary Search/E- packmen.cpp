#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
bool check(long long time, vector<long long> &food, vector<long long> &pack){
    int n = food.size();
    int m = pack.size();
    int l = 0;
    for(int r = 0; r<m; r++){
        if(l >= n){break;}
        long long p = pack[r];
        long long f = food[l];
        int mx = -1;
        if(f<p){
            long long dist = p-f;
            if(dist > time){
                return false;
            }
            int r1 = f + time-dist;
            int r2 = p + (time-dist)/2;
            mx = max(r1,r2);
        }else{
            mx = p + time;
        }
        while(l<n && food[l] <= mx){
            l++;
        }
    }
    return l>=n;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;
    string s;
    cin >> s;
    vector<long long> food, pack;
    for(int i = 0; i<n; i++){
        if(s[i] == '*'){
            food.push_back(i);
        }else if(s[i] == 'P'){
            pack.push_back(i);
        }
    }
    long long low = 0, high = 2e5 + 7;
    long long valid = high;
    while(low<=high){
        long long mid = low + (high-low)/2;
        if(check(mid,food,pack)){
            high = mid-1;
            valid = mid;
        }else{
            low = mid+1;
        }
    }
    cout << valid;
    return 0;
}
