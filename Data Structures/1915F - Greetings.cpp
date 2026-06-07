#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
long long mergeSort(vector<long long> &v, int a, int b){
    if(a>=b){
        return 0;
    }
    int mid = (a+b)/2;
    long long inv = 0;
    inv += mergeSort(v, a, mid);
    inv += mergeSort(v, mid+1, b);
    int i = a;
    int j = mid+1;
    vector<long long> temp;
    while(i<= mid && j <= b){
        if(v[i] <= v[j]){
            temp.push_back(v[i]);
            i++;
        }else{
            inv += mid-i+1;
            temp.push_back(v[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(v[i]);
        i++;
    }
    while(j<=b){
        temp.push_back(v[j]);
        j++;
    }
    for(int k = a; k<= b; k++){
        v[k] = temp[k-a];
    }
    return inv;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> start;
        map<long long, long long> saathi;
        for(int i = 0; i<n; i++){
            long long a, b;
            cin >> a >> b;
            start.push_back(a);
            saathi[a] = b;
        }
        sort(start.begin(), start.end());
        vector<long long> v;
        for(int i = 0; i<n; i++){
            v.push_back(saathi[start[i]]);
        }
        cout << mergeSort(v, 0, n-1) << "\n";
    }
    return 0;
    
}
