// Binary Search
#include <bits/stdc++.h>
using namespace std;

// binary search on sorted array
int binarySearch(const vector<int>& arr, int target) {
  int left = 0, right = arr.size() - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2; // To avoid overflow
    if (arr[mid] == target) return mid; // Target found
    else if (arr[mid] < target) left = mid + 1; // Search in the right half
    else right = mid - 1; // Search in the left half
  }
  return -1; // Target not found
}

// binary search on sorted array to find the first occurrence of target
int firstOccurrence(const vector<int>& arr, int target) {
  int left = 0, right = arr.size() - 1;
  int result = -1; // To store the index of the first occurrence
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
      result = mid; // Found a match, but continue searching to the left
      right = mid - 1;
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return result; // Return the index of the first occurrence
}

// binary search on sorted array to find the last occurrence of target
int lastOccurrence(const vector<int>& arr, int target) {
  int left = 0, right = arr.size() - 1;
  int result = -1; // To store the index of the last occurrence
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
      result = mid; // Found a match, but continue searching to the right
      left = mid + 1;
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return result; // Return the index of the last occurrence
}

// binary search on sorted array to find the number of occurrences of target
int countOccurrences(const vector<int>& arr, int target) {
  int first = firstOccurrence(arr, target);
  if (first == -1) return 0; // Target not found
  int last = lastOccurrence(arr, target);
  return last - first + 1; // Count of occurrences
}

// binary seacrch on a rotated sorted array
int findMinInRotatedArray(const vector<int>& arr) {
  int left = 0, right = arr.size() - 1;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] > arr[right]) {
      left = mid + 1; // Minimum is in the right half
    } else {
      right = mid; // Minimum is in the left half or at mid
    }
  }
  return arr[left]; // The minimum element
}

// binary search to find the index of the first element greater than target
int upperBound(const vector<int>& arr, int target) {
  int left = 0, right = arr.size() - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] <= target) {
      left = mid + 1; // Search in the right half
    } else {
      right = mid - 1; // Search in the left half
    }
  }
  return left; // Return the index of the first element greater than target
}
/*
We use upper_bound(first, last, target) to find the index of the first element greater than target.
We use lower_bound(first, last, target) to find the index of the first element not less than target.
*/