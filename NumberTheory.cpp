#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Get vector with the prime factors of number
vector < int > prime_factorization(int n){
    vector < int > factors;
    while(n % 2 == 0) factors.push_back(2), n /= 2;
    for(int i = 3; i <= sqrt(n); i += 2)
        while(n % i == 0) factors.push_back(i), n /= i;
    if(n > 2) factors.push_back(n);
    return factors;
}


//Get the factors of the a number
vector < int > factors_function(int n){
    vector < int > factors;
    while(n % 2 == 0) factors.push_back(2), n /= 2;
    for(int i = 3; i <= sqrt(n); i++)
        while(n % i == 0) factors.push_back(i), n /= i;
    if(n > 2) factors.push_back(n);
    return factors;
}


// get vector with the divisors for n
vector < int > Get_Divisors(int n){
    vector < int > divisors;
    for(int i = 1; i < sqrt(n); i++)
        if(n % i == 0) divisors.push_back(i), divisors.push_back(n / i);
    if(sqrt(n) == int(sqrt(n))) divisors.push_back(sqrt(n));
    return divisors;
}


// Check if number is prime or not
bool is_prime_function(int n){
    if(n < 2 || (n % 2 == 0 && n != 2)) return false;
    for(int i = 3; i <= sqrt(n); i += 2)
        if(n % i == 0) return false;
    return true;
}


// get the number of divisors for n
int number_of_divisors(int n){
    int divisors = 0;
    for(int i = 1; i < sqrt(n); i++)
        if(n % i == 0) divisors += 2;
    return divisors + (sqrt(n) == (int)sqrt(n));
}


// get Summation of divisors for n
int sum_of_divisors(int n){
    int sum_divisors = 0;
    for(int i = 1; i < sqrt(n); i++)
        if(n % i == 0) sum_divisors += ((n / i) + i);
    int sq = sqrt(n);
    return sum_divisors + (sq * sq == n ? sq : 0);
}


// Get how many number divisable by c between a and b
int how_many_divisors(int a, int b, int c){
    return (b / c) - ((a - 1) / c);
}


// get the summation between two numbers or the summation between 1 and n
int Summation(int r, int l = 0){
    if(l > r) swap(l, r);
    return (r * (r + 1) / 2) - (l * (l - 1) / 2);
}


// Get summation of numbers divisable by c between a and b
int Summation_of_Devisors(int a, int b, int c){
    int right = Summation(b / c);
    int left = Summation((a - 1) / c);
    return (right - left) * c;
}


// seive primes
vector < int > is_prime;
void Seive(int n){
    is_prime.assign(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= sqrt(n); i++)
        if(is_prime[i])
            for(int j = i * i; j <= n; j += i) is_prime[j] = false;
}



// sieve factorization
int N = 4e6;
vector < int > factors(N + 1 , 2);
void factorization(){
    factors[1] = 1 , factors[0] = 0;
    for(int i = 2; i<= N; i++){
        for(int j = i + i; j <=N; j += i){
            factors[j]++;
        }
    }
}




int main(){}