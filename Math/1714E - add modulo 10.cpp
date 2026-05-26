#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
// basically idea is to handle two cases ->
// if the array has numbers ending with 0 or 5 then all the numbers mustr be equal to the number ending with 0 or number ending with 5 + 5 -> number ending with zero.
// since number ending with zero doesnt change wirth any operation
// second case, if any else number ... it will follow this pattern with the operations ->
// 1->2->4->8->6->2... so (2+4+8+6) is getting repeated so we will make every number ending with 2 and then each of them must be equal after mod (%) with (2+4+8+6) = 20.


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        vector<long long> v(n);
        long long k = -1;
        for(int i = 0; i<n; i++){
            cin >> v[i];
            if(v[i]%10 == 0){
                k = v[i];
            }
            else if(v[i]%10 == 5){
                k = v[i] + 5;
                v[i] += 5;
            }
            else{
                while(v[i]%10 != 2){
                    v[i] += v[i]%10;
                }
            }
        }
        bool flag = true;
        if(k == -1){
            for(int i = 1; i<n; i++){
                if(v[i]%20 != v[i-1]%20){
                    flag = false;
                    break;
                }
            }
        }else{
            for(int i = 0; i<n; i++){
                if(v[i] != k){
                    flag = false;
                    break;
                }
            }
        }
        if(flag){
            cout << "YES" << "\n";
        }else{
            cout << "NO" << "\n";
        }

    }
    return 0;
}
