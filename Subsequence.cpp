#include <iostream>
#include <vector>
#include <cmath> // For pow
#include <chrono>

using namespace std;

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