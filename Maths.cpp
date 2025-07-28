#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
typedef long long ll;
#define int long long
#define Mod 1000000007
#define ordered_set tree<int ,  null_type ,  less_equal<> ,  rb_tree_tag ,  tree_order_statistics_node_update>
const int MAXN = 1005; // adjust as needed
int dp[MAXN][MAXN];
#define all(v) v.begin(), v.end()


ll fact(ll n)          { if(n==0) return 1; ll res = 1; for (ll i = 2; i <= n; i++) res = res * i; return res; }
ll nPr(ll n, ll r)     { return fact(n) / fact(n - r); }
ll nCr(ll n, ll r)     { return fact(n) / (fact(r) * fact(n - r)); }
ll gcd(ll a, ll b)     { if (b == 0) return a; return gcd(b, a % b); }
int GCD(int a, int b)  { return (!b ? a : GCD(b, a % b)); }
ll lcm(ll a, ll b)     { return (a * b) / gcd(a, b);}
int LCM(int a, int b)  { return a / GCD(a, b) * b; }
ll mypow(ll a, ll b)   { ll ans = 1; while(b){ if (b&1) ans = (ans*a) ; b /= 2; a = (a*a); } return ans; }
bool isPrime(ll n)     { if(n <= 1) return false; for(ll i = 2; i <= sqrt(n); i++) if(n % i == 0) return false; return true; }


// get logb(a)
double get_log(int a, int b){
    return log(a) / log(b);
}


// get the number of perfect square between l and r
int num_of_pref_squares(int l, int r){
    return ((int)(sqrtl(r)) - ceil(sqrtl(l)) + 1);
}


// Check if is perfect square
bool is_perfect_square(int n){
    int sq = sqrt(n);
    return sq * sq == n;
}


// nCr with Mod using dp

/*
memset(dp, -1, sizeof(dp)); 
initializes the memoization table so your DP function can 
distinguish between computed and uncomputed values.
*/
int nCr_db(int n, int r){
    if(n == 0 or r < 0) {return r == 0;}
    int &ret = dp[n][r];
    if(~ret) {return ret % Mod;}
    return ret = (nCr(n - 1, r - 1) % Mod + nCr(n - 1 , r) % Mod) % Mod;
}


// Combination
int nCr(int n, int r){
    if(r > n) return 0;
    int p = 1, k = 1;
    if (n - r < r) r = n - r;
    // condition for minimum choose
    if(n < 1) return 0;
    while (r > 0){
        p *= n, k *= r;
        int m = __gcd(p, k);
        p /= m, k /= m, n--, r--;
    }
    return p;
}

/*
Combination with Mod:
Modular arithmetic can be applied to compute combinations with large
numbers, requiring the use of modular inverse to handle factorials modulo a
given modulus.
*/

int mult(int a, int b){ return 1ll * a * b % Mod; }
int factt[MAXN + 1];
void buildf(){
    // initialize first in main
    factt[0] = 1;
    for(int i = 1; i <= MAXN; i++)
        factt[i] = mult(factt[i - 1], i);
}
int binary_exponentiation3(int base, int expo){
    int result = 1;
    while(expo > 0){
        if(expo & 1) result = mult(result, base);
        base = mult(base, base);
        expo >>= 1;
    }
    return result;
}
int mod_inverse12(int b, int m = Mod){
    return binary_exponentiation3(b, m - 2) % m;
}
int nCr_modd(int n, int r){
    if(r > n) return 0;
    if(r == 0 || r == n) return 1;
    return mult(factt[n], mult(mod_inverse12(factt[r]), mod_inverse12(factt[n - r])));
}
int nPr_modd(int n, int r){
    if(r > n) return 0;
    return mult(factt[n], mod_inverse12(factt[n - r]));
}


// Factorial
int factorial(int n){
    if(n < 0) return 0;
    int res = 1;
    for(int i = 2; i <= n; i++) res *= i;
    return res;
}

ll fact(ll n) { // O(n)
    if (n == 1 || n == 0) return 1;
    return n * fact(n - 1);
}

ll fib(ll n) {  // O(2^n)
    if (n == 1 || n == 2) return 1;
    return fib(n - 1) + fib(n - 2);
}


// Permutation
int nPr(int n, int r){
    if(r > n) return 0;
    int npr = 1;
    while(r-- > 0)
        npr *= n--;
    return npr;
}


// get a mod for big int
int Big_Mod(string s, int mod){
    int res = 0;
    for(auto& c : s)
        res = (res * 10 + (c - '0')) % mod;
    return res;
}


// add two number and take mod for them
void add(ll& a, int b, int mod = 1e9 + 7){
    a += b;
    if(a >= mod)
        a -= mod;
}


// b power e in O(log(n))
// Binary Exponentitation
int fast_pow(int b, int e){
    int power = 1;
    while(e){
        if(e & 1) power *= b;
        e >>= 1;
        b *= b;
    }
    return power;
}

//  Modular Inverse
/*
To find b^(-1) mod m, b and m must be coprime, meaning their greatest common
divisor is 1.
One of the methods to compute the modular inverse of b denoted by b^(-1) is
as follows:
    b^(−1) = b^(m − 2) mod m.
    For this method to work, m must be prime.

Fermat's Little Theorem::
If p is a prime number and a is an integer not divisible by p, then:
    a^(p-1) ≡ 1 (mod p)
    a^(p-2) ≡ a^(-1) (mod p)
hence: 
    a^(-1) ≡ a^(p-2) (mod p)
*/

int mod_inverse(int b, int m = Mod){
    return fast_pow(b, m - 2) % m;
}


// multiply two number and take mod for them
void mul(ll& a, int b, int mod = 1e9 + 7){
    a = ((a % mod) * (b % mod)) % mod;
}


// b power e % mod in O(log(e))
int fast_pow(int b, int e, int mod){
    int power = 1;
    while(e){
        if(e & 1) mul(power, b, mod);
        e >>= 1;
        mul(b, b, mod);
    }
    return power % mod;
}

// add two number and take mod for them
void add(ll& a, int b, int mod = 1e9 + 7){
    a += b;
    if(a >= mod)
        a -= mod;
}

// b multiply e % mod in O(log(e))
int fast_mul(int b, int e, int mod){
    int mult = 0;
    while(e){
        if(e & 1) add(mult, b, mod);
        e >>= 1;
        add(b, b, mod);
    }
    return mult % mod;
}


// print aint permutation of an array
void Print_Permutation(vector < int >& nums){
    sort(all(nums));
    do {
        for(auto& i : nums)
            cout << i << " ";
        cout << "\n";
    } while(next_permutation(nums.begin(), nums.end()));
}


// print aint permutation of a string
void Print_Permutation(string s){
    sort(all(s));
    do {
        cout << s << "\n";
    } while(next_permutation(s.begin(), s.end()));
}


// get the summation between two numbers or the summation between 1 and n
int Summation(int r, int l = 0){
    if(l > r) swap(l, r);
    return (r * (r + 1) / 2) - (l * (l - 1) / 2);
}

// get logb(a)
double get_log(int a, int b){
    return log(a) / log(b);
}

// Check if number power of another or not
const double EPS = 1e-9; // Epsilon for floating point comparison
bool is_power(int number, int base = 2){
    return (get_log(number, base) - (long long)get_log(number, base) <= EPS);
}


// Convert Decimal to any base
string decimal_to_any_base(int decimal, int base){
    if(decimal == 0) return "0";
    string num = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string result;
    do{
        result.push_back(num[decimal % base]);
        decimal /= base;
    }while(decimal != 0);
    return string(result.rbegin(), result.rend());
}


// Convert any base to decimal
int  any_base_to_decimal(string str, int base) {
    auto val = [](char c){
        return (c >= '0' && c <= '9' ? (int) c - '0' : (int) c - 'A' + 10);
    };
    int len = str.size(), power = 1, num = 0, i;
    for (i = len - 1; i >= 0; i--) {
        num += val(str[i]) * power;
        power = power * base;
    }
    return num;
}

// Kadane’s algorithm
int maxSubArraySum(vector < ll > &v)
{
    int ret = -2e9, curr = 0;
    for (int i = 0; i < v.size(); i++) {
        curr = curr + v[i];
        if (ret < curr)
            ret = curr;
        if (curr < 0)
            curr = 0;
    }
    return ret;
}




int main() {  cout<<"23";  }