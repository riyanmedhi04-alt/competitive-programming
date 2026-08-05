#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static void generate_sums(const vector<long long>& arr, vector<long long>& out, long long sum, int idx, long long mod) {
    if (idx == (int)arr.size()) {
        out.push_back(sum % mod);
        return;
    }

    generate_sums(arr, out, sum, idx + 1, mod);
    generate_sums(arr, out, (sum + arr[idx]) % mod, idx + 1, mod);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;

    vector<long long> a(n);
    vector<long long> left, right;
    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
        if (i <= n / 2) {
            left.push_back(a[i]);
        } else {
            right.push_back(a[i]);
        }
    }

    if (m == 1) {
        cout << 0 << '\n';
        return 0;
    }

    vector<long long> sums_left, sums_right;
    generate_sums(left, sums_left, 0, 0, m);
    generate_sums(right, sums_right, 0, 0, m);

    sort(sums_left.begin(), sums_left.end());

    long long best = 0;
    for (long long curr : sums_right) {
        long long need = m - 1 - curr;
        if (need < 0) need = -1;

        auto it = upper_bound(sums_left.begin(), sums_left.end(), need);
        if (it != sums_left.begin()) {
            --it;
            best = max(best, (*it + curr) % m);
        }

        auto jt = lower_bound(sums_left.begin(), sums_left.end(), m - curr);
        if (jt != sums_left.end()) {
            best = max(best, (*jt + curr) % m);
        }
    }

    cout << best << '\n';
    return 0;
}
