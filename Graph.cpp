#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 3, M = 2e4 + 4;

int n, m, u, v;

pair<int, int> edgeList[M];
bool adjMatrix[N][N];
vector<int> adjList[N];

void printNeighborsOf(int u) {
  for (int j = 0; j < m; j++) {   // O(m)
    if (edgeList[j].first == u) printf("%d ", edgeList[j].second == u);
    else if (edgeList[j].second == u) printf("%d ", edgeList[j].first == u);
  }

  for (int i = 0; i < n; i++) {   // O(n)
    if (adjMatrix[u][i] == true)
      printf("%d ", i);
  }

  for (int v : adjList[u]) {  // O(neighbors)
    printf("%d ", v);
  }
}

bool areNeighbors(int u, int v) {
  // for (int j = 0; j < m; j++) {
  //     if (edgeList[j].first == u && edgeList[j].first == v || edgeList[j].first == v && edgeList[j].first == u )
  //         return true;
  // }
  // return false;

  // return adjMatrix[u][v] == true;

  for (int y : adjList[u]) {  // O(neighbors)
    if (y == v) return true;
  }
  return false;
}

bool vis[N];

void DFS(int u) {
  vis[u] = true;
  for (int v : adjList[u])
    if (!vis[v])    DFS(v);
}


int connectedComponents() {
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      DFS(i);
      count++;
    }
  }
  return count;
}

bool vis[N];
bool isCyclic(int u, int p) {
  vis[u] = true;
  for (int v : adjList[u]) {
    if (vis[v] && v != p)   return true;
    else if (!vis[v]) {
      if (isCyclic(v, u)) return true;
    }
  }
  return false;
}

// is DAG "Directed Acyclic Graph"
const int NOT_VISITED = 0, IN_PROGRESS = 1, VISITED = 2;
bool isCyclic(int u) {
  vis[u] = IN_PROGRESS;
  for (int v : adjList[u]) {
    if (vis[v] == NOT_VISITED) {
      if (isCyclic(v))  return true;
    }
    if (vis[v] == IN_PROGRESS) {
      return true;
    }
  }
  vis[u] = VISITED;
  return false;
}



int main() {
  scanf("%d %d", &n, &m);
  for (int j = 0; j < m; j++) {
    scanf("%d %d", &u, &v);
    edgeList[j] = { u, v };

    adjMatrix[u][v] = true;
    adjMatrix[v][u] = true;     // undirected

    adjList[u].push_back(v);
    adjList[v].push_back(u);    // undirected
  }
  return 0;


  // isCyclic
  scanf("%d %d", &n, &m);
  int start;
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &u, &v);
    adjList[u].push_back(v);
    adjList[v].push_back(u);
    start = u;
  }
  puts(m == n - 1 && !isCyclic(start, -1) ? "YES" : "NO");
  return 0;


  // is a tree
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &u, &v);
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }

  int connectedComponents = 0;
  for (int u = 1; u <= n; u++) {
    if (!vis[u]) {
      connectedComponents++;
      DFS(u);
    }
  }
  puts(connectedComponents == 1 && m == n - 1 ? "YES" : "NO");
  return 0;


  // is DAG "Directed Acyclic Graph"
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &u, &v);
    adjList[u].push_back(v);
  }
  for (int i = 0; i < n; u++) {
    if (vis[i] == NOT_VISITED) {
      if (isCyclic(u)) {
        puts("Cyclic");
        return 0;
      }
    }
  }
  puts("Acyclic");
  return 0;
}