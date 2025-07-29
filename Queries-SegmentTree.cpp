/*
Segment Tree:
  is a data structure that allows for efficient range queries and updates on an array.
  It is particularly useful for problems involving range queries like sum, minimum, maximum, and XOR
  It divides the array into segments and stores information about each segment in a tree structure.
  Each node in the segment tree represents a segment of the array, and the root node represents
  the entire array.

Segment Tree Implementation for XOR Queries
This implementation allows for efficient range queries and updates on an array of integers.
It supports:
- Building the segment tree from an initial array.
- Updating a specific index in the array.
- Calculating the XOR of elements in a specified range.

*/


#include <bits/stdc++.h>
using namespace std;
#define int long long

/*Represents the data stored at each node
Contains only the XOR value for this implementation*/
struct item{
    int Xor;
};

struct segTree{
    int size;
    vector < item > Seg_Tree;
    item NEUTRAL_ITEM = {0};

    //  Combines two child nodes
    item Merge(const item & First_Item , const item & Second_Item){
      return {
          First_Item.Xor ^ Second_Item.Xor
      };
    }

    //  Creates an item from a single value
    item Single(int value){
      return {
          value
      };
    }
/*
Initializes the tree
  Allocates 4 * size space (standard for segment trees)
  Fills with neutral items
*/
    void init(int n){
      size = n;
      Seg_Tree.assign(4 * size , NEUTRAL_ITEM);
    }

    /*
    Constructs the tree from an input array
    Recursive function that builds bottom-up
    Leaf nodes store single array elements
    Internal nodes store merged results from children
    */ 
    void build(vector < int > &v , int idx , int l , int r){
        if(l == r){
            if(l < v.size())
                Seg_Tree[idx] = Single(v[l]);
            return;
        }

        int mid = l + (r - l) / 2;
        build(v , 2 * idx , l , mid);
        build(v , 2 * idx + 1, mid + 1 , r);
        Seg_Tree[idx] = Merge(Seg_Tree[2 * idx] , Seg_Tree[2 * idx + 1]);
    }

    void build(vector < int > &v){
        build(v , 1 , 0 , size - 1);
    }

    void set(int pos , int value , int idx , int l , int r){
        if(l == r){
            Seg_Tree[idx] = Single(value);
            return;
        }

        int mid = l + (r - l) / 2;
        if(pos <= mid)
            set(pos , value , 2 * idx  , l , mid);
        else
            set(pos , value , 2 * idx + 1 , mid + 1 , r);

        Seg_Tree[idx] = Merge(Seg_Tree[2 * idx] , Seg_Tree[2 * idx + 1]);
    }

    // Updates element at position 
    void set(int pos , int value){
        set(pos , value , 1 , 0 , size - 1);
    }

    item calc(int l , int r , int idx , int SegL , int SegR){
      if(SegL > r or SegR < l)
      return NEUTRAL_ITEM;
      if(SegL >= l and SegR <= r)
      return Seg_Tree[idx];
      int mid = SegL + (SegR - SegL) / 2;
      return Merge( calc(l , r , 2 * idx , SegL , mid) , calc(l , r , 2 * idx + 1 , mid + 1 , SegR));
    }
    
    // Range XOR query
    /*Returns XOR of all elements in range [l, r]
    Uses tree structure to avoid checking every element*/
    item calc(int l , int r){
        return calc(l , r , 1 , 0 , size - 1);
    }
};