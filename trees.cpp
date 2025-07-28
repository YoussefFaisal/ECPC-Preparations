#include <bits/stdc++.h>
using namespace std;

// Tree diameter ( longest path in a tree)
const int N = 1e4 + 5, M = 2e5 + 5;
int n, u, v;
vector<int> adj[N];
bool vis[N];

int farthestNode;
int longestPathLength;

void DFS(int u, int depth) {       // O(n + m)
  vis[u] = true;
  for (int v : adj[u]) {
    if (!vis[v]) {
      DFS(v, depth + 1);
    }
  }
  if (depth > longestPathLength) {
    farthestNode = u;
    longestPathLength = depth;
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  DFS(1, 0);
  memset(vis, false, sizeof vis);
  longestPathLength = 0;
  DFS(farthestNode, 0);

  printf("%d\n", longestPathLength);
  return 0;
}

// ============ Tree diameter ARABY
// Used to find the longest path in a tree, which is the diameter of the tree.

pair < int , int > findDiameter(int curr, int parent, vector < vector < int > > &adj){
  int maxDiameter = 0;
  int heights[3] = {-1 , -1 ,-1};

  for(auto &i : adj[curr]) if(i != parent) {
    auto [childDiameter , childMaxHeight] = findDiameter(i, curr, adj);
    maxDiameter = max(maxDiameter , childDiameter);
    heights[0] = childMaxHeight;
    sort(heights, heights + 3);
  }

  for(auto &height : heights)
    height = height == -1 ? 0 : height;

  return make_pair(max(maxDiameter, heights[1] + heights[2]) , heights[2] + 1);
}

int treeDiameter(int n, vector < vector < int > > &adj){
  return findDiameter(1, -1, adj).first;
}

void Solve(){

  int n; cin >> n;
  vector < vector < int > > adj(n + 1);

  for(int i=1; i<n; i++){
    int x, y; cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  cout << treeDiameter(n , adj) << "\n";
} 
