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
    long long n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> dpNeg(n), dpPos(n);
    // dpNeg[i] -> no. of subsegments ending in i, dpPos[i] -> vice versa.
    for(int i = 0; i<n; i++){
        cin >> a[i];
        if(i == 0){
            if(a[i] >0){
                dpNeg[i] = 0;
                dpPos[i] = 1;
            }else{
                dpNeg[i] = 1;
                dpPos[i] = 0;
            }
            continue;
        }
        if(a[i] > 0){
            dpNeg[i] = dpNeg[i-1];
            dpPos[i] = dpPos[i-1] +1;
        }else{
            dpNeg[i] = dpPos[i-1]  +1;
            dpPos[i] = dpNeg[i-1];
        }
    }
    long long ansNeg = 0, ansPos = 0;
    for(int i = 0; i<n; i++){
        ansNeg += dpNeg[i];
        ansPos += dpPos[i];
    }
    cout << ansNeg << " " << ansPos;
    return 0;

}
