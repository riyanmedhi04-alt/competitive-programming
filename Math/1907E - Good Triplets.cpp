#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
// Main intuition of this problem is basically combinatrics ... for adding numbers lets say 18 + 7 = 25 , now adding their dgits give 9+7 = 16 and 2+5 = 7 hence we can conclude that when a number is amde by sum of two or more numbers than its sum of digits are always less than sum of digits of the adding numbers 
// they can only be equal when sum of digits of a fixed place (lets say tens place) of the adding numbers equals the number of tens place in the target number then simple used combinatroics to calculate the possibilities and then multiply through each possible combination of digits of n and get ans !!
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long ans = 1;
        while(n>0){
            int d = n%10;
            ans *= (d+2)*(d+1)/2;
            n /= 10;
        }
        cout << ans << "\n";
    }
    return 0;
}
