#include<iostream>
using namespace std;

// Frequency array
void freq_array(){
  int n, arr[100];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int freq[100] = {0};
  for (int i = 0; i < n; i++) {
    freq[arr[i]]++;
  }

  for (int i = 0; i < 100; i++) {
    if (freq[i] > 0) {
      cout << "Element " << i << " occurs " << freq[i] << " times\n";
    }
  }
}

/*
  Prefix and Suffix Arrays
  Prefix : From 0 to i
  Suffix : From i to n-1

Prefix Sum:
  Given an array of integers 𝐴 of length 𝑁
  you need to answer 𝑄 queries that ask for
  the sum of elements from index 0 to index 𝑋.

Suffix Sum:
  Given an array of integers 𝐴 of length 𝑁
  you need to answer 𝑄 queries that ask for
  the sum of elements from index 𝑋 till end of array.
*/
void prefix_sum(){
  int n, no_of_queries, arr[100], prefix[100] = {0};
  cin >> n >> no_of_queries;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    prefix[i] = arr[i];
    if(i) prefix[i] += prefix[i - 1];
  }

  while (no_of_queries--) {
    int x; cin >> x;
    cout << "Sum from 0 to " << x << " is: " << prefix[x] << "\n";
  }
}

void suffix_sum(){
  int n, queries, arr[100], suffix[100] = {0};
  cin >> n >> queries;
  for(int i = 0; i < n;i++) cin >> arr[i];
  for(int i = n-1; i >= 0; i--){
    suffix[i] = arr[i];
    if(i < n-1) suffix[i] += suffix[i + 1];
  }
  while(queries--){
    int x; cin >> x;
    cout << "Sum from " << x << " to end is: " << suffix[x] << "\n";
  }
}

/*
Range Sum Queries:
  Given an array of integers 𝐴 of length 𝑁
  you need to answer 𝑄 queries that ask for
  the sum of elements from index 𝑋 to index 𝑌.
  This can be done using prefix sum array.
  Sum[l,r] = prefix[r] - prefix[l-1]
  Sum[l,r] = suffix[l] - suffix[r+1]
  So you need to Construct the prefix sum first.
*/

void range_sum_queries(){
  int n, queries, arr[100], prefix[100] = {0};
  cin >> n >> queries;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    prefix[i] = arr[i];
    if(i) prefix[i] += prefix[i - 1];
  }
  
  while(queries--){
    int l, r, sum; cin >> l >> r;
    sum = prefix[r];
    if (l > 0) sum -= prefix[l - 1];
    cout << "Sum from " << l << " to " << r << " is: " << sum << "\n";
  }
}

/*
Prefix Minimum:
  Given an array of integers 𝐴 of length 𝑁
  you need to answer 𝑄 queries that ask for
  the minimum element from index 0 to index 𝑋.
  This can be done using prefix min array.
  Min[l,r] = min(prefix[r], prefix[l-1])
*/

void prefix_min(){
  int n, queries, arr[100], prefix_min[100] = {0};
  cin >> n >> queries;
  for(int i = 0; i < n; i++) cin >> arr[i];
  prefix_min[0] = arr[0];
  for(int i = 1; i < n; i++) {
    prefix_min[i] = min(prefix_min[i - 1], arr[i]);
  }
  
  while(queries--){
    int x; cin >> x;
    cout << "Minimum from 0 to " << x << " is: " << prefix_min[x] << "\n";
  }
}

/*
Partial Sum Queries:
  Given an array 𝐴 of 𝑁 integers, 
  you need to apply 𝑄 queries in the form:
  𝐿 𝑅 𝑉𝐴𝐿: for each index 𝑖 (𝐿 ≤ 𝑖 ≤ 𝑅) 
  update 𝐴[𝑖] to 𝐴[𝑖] + 𝑉𝐴𝐿.

  Create array 𝐷 of size 𝑁.

Partial Sum
  1.Create an array 𝐷 of size 𝑁 initialized to 0.
  2. For each query:
    a. Set 𝐷[𝐿] += 𝑉𝐴𝐿.
    b. Set 𝐷[𝑅 + 1] -= 𝑉𝐴𝐿.
    3. Construct the prefix sums of array 𝐷 in-place.
    4. Set 𝐴[𝑖] += 𝐷[𝑖] for each index 𝑖.
*/

void partial_sum_queries(){
  int n, queries, arr[100], diff[100] = {0};
  cin >> n >> queries;
  for(int i = 0; i < n; i++) cin >> arr[i];
  
  while(queries--){
    int l, r, val; cin >> l >> r >> val;
    diff[l] += val;
    diff[r + 1] -= val;
  }
  
  for(int i = 0; i < n; i++) {
    if(i > 0) diff[i] += diff[i - 1];
    arr[i] += diff[i];
  }
  
  for(int i = 0; i < n; i++) cout << arr[i] << " ";
}

int main(){}