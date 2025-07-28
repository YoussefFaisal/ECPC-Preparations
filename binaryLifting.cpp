/*
Binary Lifting Technique (Tree Ancestor Queries)
This technique is used to efficiently answer queries about the k-th ancestor of a node in a tree.

*/

#include <bits/stdc++.h> // E
using namespace std;
#define int long long

void Solve(){
  int n , q; cin >> n >> q;
  vector < int > v(n - 1);
  for(auto &i : v)
    cin >> i;

  int Log = 0;
  while((1 << Log) <= n)
    Log++;

  vector < vector < int > > parent(n + 1, vector < int > (Log));
  parent[1][0] = -1;
  for(int i=2; i<=n; i++)
    parent[i][0] = v[i - 2];

  for(int j=1; j<Log; j++)
    for(int i=1; i<=n; i++)
      parent[i][j] = parent[i][j - 1] == -1 ? -1 : parent[ parent[i][j - 1] ][j - 1];

  while(q--){
    int node, k; cin >> node >> k;

    for(int i=0; i<Log and node != -1; i++)
      if(k & (1 << i))
        node = parent[node][i];

    cout << node << "\n";
  }
} 
