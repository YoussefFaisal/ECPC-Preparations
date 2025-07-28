#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;

#define cin2d(vec, n, m) for(int i = 0; i < n; i++) for(int j = 0; j < m && cin >> vec[i][j]; j++);
#define cout2d(vec , n , m) for(int i = 0; i < n; i++, cout << "\n") for(int j = 0; j < m && cout << vec[i][j] << " "; j++);
#define cout_map(mp) for(auto& [first, second] : mp) cout << first << " --> " << second << "\n";
#define put(s) return void(cout << s << dl);
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";
#define fixed(n) fixed << setprecision(n)
#define ceil(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define sz(x) int(x.size())
#define ll long long
#define ull unsigned long long
#define dl "\n"

const ll Mod = 1e9 + 7;
/*
Purpose: Allows you to read values directly into a vector from an input stream (like cin).
How it works: Iterates over each element in the vector v and reads a value from the stream into it.
Gotcha: The vector must already be sized; this does not add new elements. If v is empty, nothing is read.
Example usage:
vector<int> v(5); // Pre-size the vector to hold 5 integers
*/
template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x : v) in >> x;
    return in;
}

/*
Purpose: Allows you to print a vector directly to an output stream (like cout).
How it works: Iterates over each element in the vector and writes it to the stream, separated by spaces.
Gotcha: The vector can be empty, in which case nothing is printed.
Example usage:
vector<int> v = {1, 2, 3};
cout << v; // Output: 1 2 3

*/
template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) {
    for (const T &x: v) out << x << ' ';
    return out;
}

//--------------------------------------------------------------------------------


// Function to find the minimum cyclic string
// This function finds the lexicographically smallest string that can be formed by cyclically shifting the input string.

string min_cyclic_string(string s) {
  s += s;
  int n = sz(s);
  int i = 0, ans = 0;
  while (i < n / 2) {
    ans = i;
    int j = i + 1, k = i;
    while (j < n && s[k] <= s[j]) {
      if (s[k] < s[j])
        k = i;
      else
        k++;
      j++;
    }
    while (i <= k)
      i += j - k;
  }
  return s.substr(ans, n / 2);
}

/*
Hashing is a technique used to convert a string into a fixed-size
integer value, which can be used for quick comparisons and lookups.
Hash value of a string is: 
- A numerical representation of the string.
- It is computed using a polynomial rolling hash function.
- The hash value is used to efficiently compare strings and detect duplicates.

Use Cases:
- String matching algorithms (like Rabin-Karp).
- Detecting anagrams.
- Storing strings in hash tables.
- Comparing large strings quickly.

Problem Solving Use Cases:
- Efficiently checking if two strings are anagrams.
- Grouping strings with the same characters.
- Finding unique substrings in a string.

Example:
- The hash value of the string "abc" is computed as follows:
  - Each character is assigned a value (a=1, b=2, c=3).
  - The hash value is calculated using the formula: 
    hash = (1 * p^0 + 2 * p^1 + 3 * p^2) % m
  - Where p is a prime number and m is a large modulus.
*/
ll compute_hash(string& s) {
  const int p = 31 , m = 1e9 + 9;
  ll hash_value = 0, p_pow = 1;

  for (char &c : s) {
    hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
    p_pow = (p_pow * p) % m;
  }
  return hash_value;
}

// Group strings by their hash values
/*
Each string is hashed, and strings with the same hash value are grouped together.
example:
- Input: ["abc", "bca", "cab", "xyz"]
- Output: [[abc, bca, cab], [xyz]]
- Explanation: The strings "abc", "bca", and "cab" are anagrams of each other and are grouped together.
*/

vector < vector < int > > group_strings(vector < string >& s) {
  int n = sz(s);
  vector < pair < ll, int > > hashes(n);
  for (int i = 0; i < n; i++)
    hashes[i] = {compute_hash(s[i]), i};

  sort(all(hashes));

  vector< vector < int > > groups;
  for (int i = 0; i < n; i++) {
    if (i == 0 or hashes[i].first != hashes[i-1].first)
      groups.emplace_back();
    groups.back().push_back(hashes[i].second);
  }
  return groups;
}



int count_unique_substrings(string const& s) {
    int n = sz(s);

    const int p = 31, m = 1e9 + 9;
    vector < ll > p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector < ll > h(n + 1, 0);
    for (int i = 0; i < n; i++)
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;

    int cnt = 0;
    for (int l = 1; l <= n; l++) {
        set < ll > hs;
        for (int i = 0; i <= n - l; i++) {
            ll cur_h = (h[i + l] + m - h[i]) % m;
            cur_h = (cur_h * p_pow[n-i-1]) % m;
            hs.insert(cur_h);
        }
        cnt += sz(hs);
    }
    return cnt;
}

// Function to find the longest common prefix of two strings
string longest_common_prefix(const string& s1, const string& s2) {
  int n = min(sz(s1), sz(s2));
  int i = 0;
  while (i < n && s1[i] == s2[i]) {
    i++;
  }
  return s1.substr(0, i);
}

// Function to find the longest common prefix of a vector of strings
string longest_common_prefix(const vector<string>& strs) {
  if (strs.empty()) return "";
  string prefix = strs[0];
  for (int i = 1; i < sz(strs); i++) {
    prefix = longest_common_prefix(prefix, strs[i]);
    if (prefix.empty()) break; // No common prefix found
  }
  return prefix;
}

// Function to find the longest common suffix of two strings
string longest_common_suffix(const string& s1, const string& s2) {
  int n1 = sz(s1), n2 = sz(s2);
  int i = 0;
  while (i < n1 && i < n2 && s1[n1 - 1 - i] == s2[n2 - 1 - i]) {
    i++;
  }
  return s1.substr(n1 - i, i);
}

// Function to find the longest common suffix of a vector of strings
string longest_common_suffix(const vector<string>& strs) {
  if (strs.empty()) return "";
  string suffix = strs[0];
  for (int i = 1; i < sz(strs); i++) {
    suffix = longest_common_suffix(suffix, strs[i]);
    if (suffix.empty()) break; // No common suffix found
  }
  return suffix;
}

// Function to find the longest palindromic substring in a string
string longest_palindromic_substring(const string& s) {
  int n = sz(s);
  if (n == 0) return "";

  vector<vector<bool>> dp(n, vector<bool>(n, false));
  int start = 0, maxLength = 1;

  for (int i = 0; i < n; i++) {
    dp[i][i] = true; // Single character is a palindrome
  }

  for (int i = 0; i < n - 1; i++) {
    if (s[i] == s[i + 1]) {
      dp[i][i + 1] = true;
      start = i;
      maxLength = 2;
    }
  }

  for (int length = 3; length <= n; length++) {
    for (int i = 0; i <= n - length; i++) {
      int j = i + length - 1;
      if (s[i] == s[j] && dp[i + 1][j - 1]) {
        dp[i][j] = true;
        start = i;
        maxLength = length;
      }
    }
  }

  return s.substr(start, maxLength);
}

// Function to find the longest palindromic substring in a vector of strings
vector<string> longest_palindromic_substring(const vector<string>& strs) {
  if (strs.empty()) return {};
  string lps = longest_palindromic_substring(strs[0]);
  for (int i = 1; i < sz(strs); i++) {
    lps = longest_palindromic_substring(lps + strs[i]);
    if (lps.empty()) break; // No palindromic substring found
  }
  return {lps};
}

