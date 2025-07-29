/*
Topological Sort using Kahn's Algorithm (Graph)
This algorithm uses a queue to process nodes with zero in-degree
It ensures that all nodes are processed in a valid topological order
If a cycle is detected (not all nodes are processed), it returns "IMPOSSIBLE"
Otherwise, it returns the topological order of nodes
Use Cases (Competitive Programming):
- Scheduling tasks with dependencies.
- Course prerequisite problems.
- Finding a valid order of operations in directed acyclic graphs (DAGs).

example:
Input:
5 4
1 2
1 3
2 4
3 4
Output:
1 2 3 4 5
*/

#include <bits/stdc++.h>
using namespace std;
#define put(s) return void(cout << s << dl);
#define all(vec) vec.begin(), vec.end()
#define sz(x) int(x.size())
#define ll long long
#define dl "\n"
const ll Mod = 1e9 + 7;
template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x : v) in >> x;
    return in;
}
template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) {
    for (const T &x: v) out << x << ' ';
    return out;
}

ll n , m;
vector < int > in_degree;
vector < set < int > > adj;

// Initialize the graph with n nodes and m edges
// Each edge is directed from i to j

void init(){
  cin >> n >> m;
  in_degree.assign(n + 1 , 0);
  adj.assign(n + 1 , {});
  map < pair < int ,int > , bool > check;
  while(m--){
    int i , j; cin >> i >> j;

    if(check[{i , j}])
      continue;

    in_degree[j]++;
    adj[i].emplace(j);
    check[{i, j}] = true;
  }
}

void Solve(){
  init();

  queue < int > order;
  for(int i=1; i<=n; i++){
    if(!in_degree[i])
      order.push(i);
  }

  int cnt = 0;
  vector < int > ans;

  while(!order.empty()){
    int curr = order.front();
    order.pop();
    ans.push_back(curr);

    for(auto &i : adj[curr]){
      if(!(--in_degree[i]))
        order.push(i);
    }
    cnt++;
  }
  if(cnt != n) put("IMPOSSIBLE");
  cout << ans << dl;
}

int32_t main(){ int tc = 1; for(int i=1; i<=tc; i++){ /*cout << "Scenario #" << i << ":" << dl;*/ Solve(); } }