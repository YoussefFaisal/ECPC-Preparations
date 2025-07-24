// Two Pointers & Sliding Window
#include <bits/stdc++.h>
using namespace std;

/*

Types of Problems It Solves
1. Foundational Two Pointers Problems
  Scenarios that do not involve a window or segment of the array:
    Finding two values in a sorted array that sum up to T.
    Merging two sorted arrays in linear time.

2. Variable Sized Window Problems
  Problems where you need to find a subarray within an array that meets a
  certain condition, and the size of this window is not fixed.
Such as:
  - Finding the longest subarray with sum ≤ k
  (or the shortest subarray with sum > k).
  - Finding the longest substring without repeating characters.

3. Fixed Sized Window Problems (Sliding Window)
  - Finding the maximum sum subarray of size k.
  - Finding the maximum of every subarray of size k.
*/
/*

// Two-Sum Problem
Given a sorted array A of length N and target T,
find two indices i and j such that A[i] + A[j] = T, where i < j.
*/

pair<int, int> twoSum(vector<int>& A, int T) {
  int j = A.size() - 1;
  for (int i = 0; i < A.size(); i++) {
    while (j > i && A[i] + A[j] > T) {
      j--;
    }
    if (A[i] + A[j] == T) {
      return {i, j}; // Return indices as a pair
    }
  }
  return {-1, -1}; // Return -1, -1 if no such indices exist
}
/*
Subarray sum problem
Given unsorted array A of N positive integers and a 
Target Sum T, find a subarray whose sum = T.
*/
// Using two pointers to find a subarray with sum = T
bool subarraySum(vector<int>& A, int T) {
  int left = 0, right = 0, sum = 0;
  while (right < A.size()) {
    sum += A[right];
    while (sum > T && left <= right) {
      sum -= A[left++];
    }
    if (sum == T) {
      return true; // Found a subarray with the target sum
    }
    right++;
  }
  return false; // No such subarray exists
}

// Longest subarray with sum < k using two pointers
vector<int> longestSubarrayWithSumLessThanK(vector<int>& A, int k) {
  int left = 0, sum = 0, maxLen = 0, start = 0;
  for (int right = 0; right < A.size(); right++) {
    sum += A[right];
    while (sum >= k && left <= right) {
      sum -= A[left++];
    }
    if (right - left + 1 > maxLen) {
      maxLen = right - left + 1;
      start = left;
    }
  }
  return vector<int>(A.begin() + start, A.begin() + start + maxLen);
}

// Longest substring without repeating characters using two pointers
string longestSubstringWithoutRepeatingChars(const string& s) {
  unordered_map<char, int> charIndex;
  int left = 0, maxLen = 0, start = 0;
  for (int right = 0; right < s.size(); right++) {
    if (charIndex.count(s[right]) && charIndex[s[right]] >= left) {
      left = charIndex[s[right]] + 1;
    }
    charIndex[s[right]] = right;
    if (right - left + 1 > maxLen) {
      maxLen = right - left + 1;
      start = left;
    }
  }
  return s.substr(start, maxLen);
}

// Longest substring with at most k distinct characters using two pointers
string longestSubstringWithKDistinctChars(const string& s, int k) {
  unordered_map<char, int> charCount;
  int left = 0, maxLen = 0, start = 0;
  for (int right = 0; right < s.size(); right++) {
    charCount[s[right]]++;
    while (charCount.size() > k) {
      charCount[s[left]]--;
      if (charCount[s[left]] == 0) {
        charCount.erase(s[left]);
      }
      left++;
    }
    if (right - left + 1 > maxLen) {
      maxLen = right - left + 1;
      start = left;
    }
  }
  return s.substr(start, maxLen);
}

// Maximum sum subarray of size k using sliding window
int maxSumSubarrayOfSizeK(const vector<int>& A, int k) {
  if (k > A.size()) return -1; // Invalid case
  int maxSum = 0, currentSum = 0;
  
  // Calculate the sum of the first k elements
  for (int i = 0; i < k; i++) {
    currentSum += A[i];
  }
  maxSum = currentSum;

  // Slide the window across the array
  for (int i = k; i < A.size(); i++) {
    currentSum += A[i] - A[i - k];
    maxSum = max(maxSum, currentSum);
  }
  
  return maxSum;
}

// Max subarray of size k using sliding window
vector<int> maxSubarrayOfSizeK(const vector<int>& A, int k) {
  if (k > A.size()) return {}; // Invalid case
  vector<int> result;
  deque<int> dq; // Store indices of useful elements

  // Process the first k elements
  for (int i = 0; i < k; i++) {
    while (!dq.empty() && A[dq.back()] <= A[i]) {
      dq.pop_back();
    }
    dq.push_back(i);
  }
  result.push_back(A[dq.front()]);

  // Process the rest of the elements
  for (int i = k; i < A.size(); i++) {
    while (!dq.empty() && dq.front() <= i - k) {
      dq.pop_front(); // Remove elements not in the current window
    }
    while (!dq.empty() && A[dq.back()] <= A[i]) {
      dq.pop_back(); // Maintain decreasing order in deque
    }
    dq.push_back(i);
    result.push_back(A[dq.front()]);
  }

  return result;
}