#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
struct Sieve {
    int n;
    vector<int> spf;    // spf[i] stores the smallest prime factor of i
    vector<int> primes; // stores all prime numbers up to n

    Sieve(int n) : n(n), spf(n + 1) {
        for (int i = 0; i <= n; ++i) {
            spf[i] = i;
        }
        for (int i = 2; i * i <= n; ++i) {
            if (spf[i] == i) {
                for (int j = i * i; j <= n; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }
        for (int i = 2; i <= n; ++i) {
            if (spf[i] == i) {
                primes.push_back(i);
            }
        }
    }

    // O(1) primality check
    bool is_prime(int x) const {
        if (x < 2 || x > n) return false;
        return spf[x] == x;
    }

    // O(log X) prime factorization returning pairs of {prime_factor, count}
    vector<pair<int, int>> get_factorization(int x) const {
        vector<pair<int, int>> factors;
        while (x > 1) {
            int p = spf[x];
            int count = 0;
            while (x % p == 0) {
                count++;
                x /= p;
            }
            factors.push_back({p, count});
        }
        return factors;
    }

    // O(log X) list of distinct prime factors
    vector<int> get_prime_factors(int x) const {
        vector<int> factors;
        while (x > 1) {
            int p = spf[x];
            factors.push_back(p);
            while (x % p == 0) {
                x /= p;
            }
        }
        return factors;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    const int N = 6e6;
                vector<int> p, ip(N, 1);
  for (int i = 2; i < N; ++i) {
    if (!ip[i]) continue;
    p.push_back(i);
    for (int j = i; j < N; j += i) {
      ip[j] = 0;
    }
  }

    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        vector<long long> a(n);
        for(int i = 0; i<n; i++){
            cin >> a[i];
        }

        sort(a.rbegin(),a.rend());
        long long ans = 0;
        long long sum = 0, sump= 0;
        for(int i = 0; i<n; i++){
            sum += a[i];
            sump += p[i];
            if(sum >= sump){
                ans++;
            }
        }
        cout << n- ans << "\n";
    }
    return 0;
}
