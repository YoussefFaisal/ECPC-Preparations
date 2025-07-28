#include <bits/stdc++.h>
using namespace std;

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


void generateSubsequencesBitwise(const vector<int> &arr)
{
  int n = arr.size();
  int num_subsequences = pow(2, n);
  int count = 0;

  cout << "All subsequences:" << endl;
  for (int counter = 0; counter < num_subsequences; ++counter)
  {
    // cout << "[";
    for (int j = 0; j < n; ++j)
    {
      // Check if the j-th bit is set in the counter
      if ((counter >> j) & 1)
      {
        // cout << arr[j];
        if (j < n - 1 && ((counter >> (j + 1)) & 1) || (j < n - 1 && !((counter >> (j + 1)) & 1) && (counter & (~((1 << (j + 1)) - 1)))))
        {
          // cout << ", ";
        }
      }
    }
    // cout << "]" << "\n";
    count++;
  }
  cout << "Total number of subsequences: " << num_subsequences << endl;
}

void findSubsequencesRecursive(int curr_index, const vector<int> &arr, vector<int> &current_subsequence, vector<vector<int>> &result)
{
  // Base case: When we reach the end of the array
  if (curr_index == arr.size())
  {
    result.push_back(current_subsequence);
    return;
  }

  // Include the current element
  current_subsequence.push_back(arr[curr_index]);
  findSubsequencesRecursive(curr_index + 1, arr, current_subsequence, result);
  current_subsequence.pop_back(); // Backtrack

  // Exclude the current element
  findSubsequencesRecursive(curr_index + 1, arr, current_subsequence, result);
}

// from l to r
void findSubsequences(const vector<int> &arr, int l, int r, int index, vector<int> &current_subsequence, vector<vector<int>> &all_subsequences)
{
  // Base case: If we've processed all elements in the range
  if (index > r)
  {
    all_subsequences.push_back(current_subsequence);
    return;
  }

  // Exclude the current element
  findSubsequences(arr, l, r, index + 1, current_subsequence, all_subsequences);

  // Include the current element
  current_subsequence.push_back(arr[index]);
  findSubsequences(arr, l, r, index + 1, current_subsequence, all_subsequences);
  current_subsequence.pop_back(); // Backtrack: Remove the element for other possibilities
}

vector<vector<int>> generateSubsequences(const vector<int> &arr, int l, int r)
{
  vector<vector<int>> all_subsequences;
  vector<int> current_subsequence;
  findSubsequences(arr, l, r, l, current_subsequence, all_subsequences);
  return all_subsequences;
}


// Function to find the longest increasing subsequence in a vector of integers
int longest_increasing_subsequence(const vector<int>& nums) {
    if (nums.empty()) return 0;
    vector<int> dp;
    
    for (int num : nums) {
        auto it = lower_bound(dp.begin(), dp.end(), num);
        if (it == dp.end()) {
        dp.push_back(num); // Append to the end
        } else {
        *it = num; // Replace the first element greater than or equal to num
        }
    }
    
    return dp.size(); // Length of the longest increasing subsequence
}

// Function to find the longest common subsequence of two strings
int longest_common_subsequence(const string& s1, const string& s2) {
  int n = sz(s1), m = sz(s2);
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  return dp[n][m];
}

// Function to find the longest common subsequence of a vector of strings
int longest_common_subsequence(const vector<string>& strs) {
  if (strs.empty()) return 0;
  string lcs = strs[0];
  for (int i = 1; i < sz(strs); i++) {
    lcs = longest_common_subsequence(lcs, strs[i]);
    if (lcs.empty()) break; // No common subsequence found
  }
  return sz(lcs);
}



// Function to find the longest increasing subsequence in a vector of strings
vector<string> longest_increasing_subsequence(const vector<string>& strs) {
  int n = sz(strs);
  if (n == 0) return {};

  vector<int> dp(n, 1);
  vector<int> prev(n, -1);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (strs[i] > strs[j] && dp[i] < dp[j] + 1) {
        dp[i] = dp[j] + 1;
        prev[i] = j;
      }
    }
  }

  int maxLength = *max_element(dp.begin(), dp.end());
  vector<string> lis;
  for (int i = maxLength - 1, idx = max_element(dp.begin(), dp.end()) - dp.begin(); i >= 0; i--) {
    lis.push_back(strs[idx]);
    idx = prev[idx];
  }
  
  reverse(lis.begin(), lis.end());
  return lis;
}

// Function to find the longest increasing subsequence in a vector of integers
int longest_increasing_subsequence(const vector<int>& nums) {
    if (nums.empty()) return 0;
    vector<int> dp;
    
    for (int num : nums) {
        auto it = lower_bound(dp.begin(), dp.end(), num);
        if (it == dp.end()) {
        dp.push_back(num); // Append to the end
        } else {
        *it = num; // Replace the first element greater than or equal to num
        }
    }
    
    return dp.size(); // Length of the longest increasing subsequence
}



int main()
{
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

  auto start = chrono::high_resolution_clock::now();
  vector<vector<int>> all_subsequences;
  vector<int> current_subsequence;

  findSubsequencesRecursive(0, arr, current_subsequence, all_subsequences);

  // cout << "All subsequences:" << endl;
  // for (const auto &sub : all_subsequences)
  // {
  //   cout << "[";
  //   for (size_t i = 0; i < sub.size(); ++i)
  //   {
  //     cout << sub[i];
  //     if (i < sub.size() - 1)
  //     {
  //       cout << ", ";
  //     }
  //   }
  //   cout << "]" << endl;
  // }

  generateSubsequencesBitwise(arr);

  
  int l = 1; // Starting index (inclusive)
  int r = 3; // Ending index (inclusive)
  vector<vector<int>> subsequences = generateSubsequences(arr, l, r);
  cout << "Number of Subsequences from index " << l << " to " << r << ":" << endl;
  cout << subsequences.size() << endl;


  // Measure time taken
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double> duration = end - start;
  cout << "Time taken: " << duration.count() << " seconds" << endl;
  return 0;
}

// O(2^n * n) time complexity