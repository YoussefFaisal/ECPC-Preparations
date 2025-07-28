#include <bits/stdc++.h> // E
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;

#define fixed(n) fixed << setprecision(n)
#define ceil(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
#define dl "\n"
#define ordered_set tree<int ,  null_type ,  less_equal<> ,  rb_tree_tag ,  tree_order_statistics_node_update>
#define int long long
#define all(v) v.begin(), v.end()
#define INF 2000000000000000000
#define Mod 998244353

int n , m;
vector < vector < int > > adj, comps;
vector < int > inStack, depth, lowLink, comp;
stack < int > st;
int currDepth = 0;

/*
Tarjan's Algorithm for finding strongly connected components (SCCs) in a directed graph.
  - Uses depth-first search (DFS) to explore the graph.
  - Each node is assigned a depth and a low-link value.
  - Uses depth-first search (DFS) to discover SCCs in a directed graph.
  - Each SCC is a maximal subgraph where every vertex is reachable from every other vertex in the subgraph.
  - The algorithm maintains a stack to keep track of the nodes in the current SCC.
  - When a node's low-link value equals its depth, it indicates the root of an SCC.
*/
void tarjan(int curr){
  lowLink[curr] = depth[curr] = currDepth++;
  inStack[curr] = 1;
  st.push(curr);

  for(auto &i : adj[curr]){
    if(depth[i] == -1){
      tarjan(i);
      lowLink[curr] = min(lowLink[curr], lowLink[i]);
    }
    else if(inStack[i])
      lowLink[curr] = min(lowLink[curr], lowLink[i]);
  }

  if(lowLink[curr] == depth[curr]){
    comps.push_back(vector < int > ());
    int x = -1;
    while(x != curr){
      x = st.top();
      st.pop();
      inStack[x] = 0;
      comps.back().push_back(x);
      comp[x] = comps.size() - 1;
    }
  }
}

void Solve(){
  cin >> n >> m;
  adj.assign(n, vector < int > ());
  inStack.assign(n, 0);
  depth.assign(n, -1);
  lowLink.assign(n, -1);
  comp.assign(n, -1);
  currDepth = 0;

  for(int i = 0; i < m; i++){
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u); // undirected graph
  }

  for(int i = 0; i < n; i++){
      if(depth[i] == -1)
          tarjan(i);
  }

  cout << "Number of strongly connected components: " << comps.size() << dl;
  for(auto &c : comps){
      cout << "Component: ";
      for(auto &x : c)
          cout << x << " ";
      cout << dl;
  }
} 

int32_t main(){
  int testCases=1;
  // cin >> testCases;
  // bool first = true;
  while(testCases--){
      // if(not first)
      //     cout << dl;
      Solve();
      // first = false;
  }
  return 0;
}