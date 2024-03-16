Sieve of Eratosthenes is an algorithm for finding all the prime numbers in a segment $[1;n]$ using  $O(n \log \log n)$ operations.

```
int n;
vector<bool> is_prime(n+1, true);
is_prime[0] = is_prime[1] = false;
for (int i = 2; i <= n; i++) {
    if (is_prime[i] && (long long)i * i <= n) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
}
```
Optimized version
```
// original O(nlog(n)log(n))
// current implementation O(nln(n)ln(sqrt(n)))
const int N = 1e5;
vector<bool> is_prime(N + 1, true);
// vector<int> primes;
int init = [](){
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (is_prime[i]) {
			// primes.push_back(i);
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return 0;
}();

```
reference // https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html
