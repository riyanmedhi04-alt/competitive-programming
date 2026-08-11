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
        long long px, py, qx, qy, rx, ry, sx,sy;
        cin >> px >> py >> qx >> qy >> rx >> ry >> sx >> sy;
        long long dum = 2* ((1LL*(py-qy)*(sx-rx)) - (1LL*(qx-px)*(ry-sy)));
        if(dum == 0){
            // Midpoint of RS scaled by 2:
        long long mx2 = rx + sx;
        long long my2 = ry + sy;

        // Squared distance from 2*P to 2*M_RS
        long long distP_sq = (2 * px - mx2) * (2 * px - mx2) + (2 * py - my2) * (2 * py - my2);

        // Squared distance from 2*Q to 2*M_RS
        long long distQ_sq = (2 * qx - mx2) * (2 * qx - mx2) + (2 * qy - my2) * (2 * qy - my2);

        if (distP_sq == distQ_sq) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
        }else{
            cout << "Yes" << "\n";
        }
    }
    return 0;
}
