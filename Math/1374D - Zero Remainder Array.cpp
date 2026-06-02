#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

/*
Codeforces 1374D - Zero Remainder Array

Key Idea:
For every element a[i] that is not divisible by k, compute:

    diff = k - (a[i] % k)

This is the minimum number of increments needed to make a[i]
divisible by k.

If multiple elements have the same diff, they cannot all finish
after exactly diff moves. After one element uses 'diff', the next
one with the same diff must wait an additional k moves, then the
next one another k moves, and so on.

For a particular diff:
    1st occurrence -> diff
    2nd occurrence -> diff + k
    3rd occurrence -> diff + 2*k
    ...

We keep track of the largest such value. The final answer is
that value + 1.
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        long long n, k;
        cin >> n >> k;

        set<long long> s;
        map<long long, long long> m;

        long long ans = 0;

        for(int i = 0; i < n; i++){
            long long x;
            cin >> x;

            if(x % k != 0){

                // Minimum increments required to make x divisible by k.
                long long diff = k - (x % k);

                // First occurrence of this diff.
                if(s.find(diff) == s.end()){
                    s.insert(diff);

                    // Reserve this diff for future collisions.
                    m[diff]++;

                    ans = max(ans, diff);
                }
                else{
                    // Previous elements already require the same diff.
                    // Each previous occurrence pushes the current one
                    // forward by an additional k moves.
                    long long diff1 = diff + k * m[diff];

                    m[diff]++;

                    ans = max(ans, diff1);
                }
            }
        }

        if(ans == 0){
            cout << 0 << "\n";
        }
        else{
            cout << ans + 1 << "\n";
        }
    }

    return 0;
}
