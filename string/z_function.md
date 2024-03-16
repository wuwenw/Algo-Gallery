**Z-function**
Suppose we are given a string $s$ of length $n$ . The Z-function for this string is an array of length $n$  where the $i$ -th element is equal to the greatest number of characters starting from the position $i$  that coincide with the first characters of $s$ .

In other words, $z[i]$  is the length of the longest string that is, at the same time, a prefix of $s$  and a prefix of the suffix of $s$  starting at $i$ .

For example, here are the values of the Z-function computed for different strings:

"aaaaa" -  
$[0, 4, 3, 2, 1]$ 
"aaabaab" -  
$[0, 2, 1, 0, 2, 1, 0]$ 
"abacaba" -  
$[0, 0, 1, 0, 3, 0, 1]$ 

Reference https://cp-algorithms.com/string/z-function.html

---

brute force approach
```
O(n^2)
vector<int> z_function_trivial(string s) {
  int n = (int)s.length();
  vector<int> z(n);
  for (int i = 1; i < n; ++i)
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
  return z;
}
```
Reference https://oi-wiki.org/string/z-func/

---

We can maintain a z-box for matched substrings, and try to reuse it for future match. z-box can be extended if current character has longer matches. 

Once go beyond the z-box boundary, fall back to brute force match.

```
// O(n)
vector<int> z_function(const vector<int>& s) {
    int n = s.size();
    vector<int> z(n);
    // left and right of zbox
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        // current index i is within zbox
        if (i <= r) {
            // choose min(matched z, distance to right boundary)
            z[i] = min(z[i - l], r - i + 1);
        }
        // brute force match towards the end
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}
```