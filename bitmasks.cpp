// Bitmasks and iterative complete search
#include <bits/stdc++.h>
using namespace std;

/*
Bitwise operations
  - AND: & 
    returns a 1 in each bit position where both operands have a 1

    - OR: |
    returns a value with a 1 in each bit position 
    where at least one of the operands has a 1

  - XOR: ^
    returns a value with a 1 in each bit position 
    where the corresponding bits of the operands are different
    (it's like asking are the bits different?)

  - NOT: ~
    inverts all bits of the operand
    (it's like asking what is the opposite?)
    When dealing with signed integers, NOT can lead to unexpected results
    due to the way negative numbers are represented in binary.

  - Left Shift: <<
    shifts all bits of the operand to the left by a specified number of positions
    (it's like multiplying by 2 for each shift)

  - Right Shift: >>
    shifts all bits of the operand to the right by a specified number of positions
    (it's like dividing by 2 for each shift)

All the bitwise operations are commutative, meaning that:
  - a & b == b & a
  - a | b == b | a
  - a ^ b == b ^ a
*/

/*
BitMasking
  Bit masking is a technique used in computer programming to manipulate individual bits or groups of bits.
  Bits are numbered from RIGHT to LEFT starting from index 0 (2⁰).
*/

// Check if the bit at position 'bit' is set(equal to 1)
bool isSet(int mask, int bit) {
    return (mask & (1 << bit)) != 0; 
    // or return mask & (1 << bit);
}

// Set the bit at position 'bit' to 1
void setBiton(int &mask, int bit) {
    mask |= (1 << bit);
}

// Set the bit at position 'bit' to 0
void turnOffBit(int &mask, int bit) {
    mask &= ~(1 << bit); // or mask ^= (1 << bit);
}

// Toggle the bit at position 'bit' (if it's 1, it becomes 0; if it's 0, it becomes 1)
bool toggleBit(int &mask, int bit) {
    return mask ^ (1 << bit);
}
void toggle(int &mask, int bit) {
    mask ^= (1 << bit);
}

bool countOnes(int mask){
  return __builtin_popcount(mask); // returns the number of 1s in the binary representation of mask
}

/*
iterative complete search
  Complete search (aka brute force) is a method for solving 
  a problem by traversing the entire search space in search of a solution.
*/

void allSubsets(int n) {
  for (int mask = 0; mask < (1 << n); mask++) { // 1 << n is 2^n
    for (int bit = 0; bit < n; bit++) {
      if (isSet(mask, bit)) {
        cout << bit << " ";
      }
    }
    cout << endl;
  }
}

int countSubsets(int n) {
  return 1 << n; // 2^n
}

// Subset of array
vector<int> getSubset(int mask) {
  vector<int> subset;
  for (int bit = 0; bit < 32; bit++) { // assuming mask is a 32-bit integer
    if (isSet(mask, bit)) {
      subset.push_back(bit);
    }
  }
  return subset;
}


int main(){}