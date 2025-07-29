/*
Bellman-Ford algorithm is a graph algorithm that finds the shortest paths 
from a single source vertex to all other vertices in a ((weighted directed graph)),
even if the graph contains negative edge weights
*/
#include <bits/stdc++.h>

using namespace std;
#define add_mod(a, b, m) (((a % m) + (b % m)) % m)
#define sub_mod(a, b, m) (((a % m) - (b % m) + m) % m)
#define mul_mod(a, b, m) (((a % m) * (b % m)) % m)
#define ll long long
constexpr int INF = 1 << 30, Mod = 1e9 + 7; constexpr ll LINF = 1LL << 62;
#define PI acos(-1)
template < typename T = int > using Pair = pair < T, T >;

template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x : v) in >> x;
    return in;
}

template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) { 
    for (const T &x : v) out << x << ' '; 
    return out;
}

template < typename T = int > struct BellmanFord {
    
    struct Edge {
        int u, v;
        T w;

        Edge(int _u = 0, int _v = 0, T _w = 0) : u(_u), v(_v), w(_w) {}

        friend istream& operator >> (istream &in, Edge &e) {
            in >> e.u >> e.v >> e.w;
            return in;
        }
 
        void inv(){
            w *= -1;
        }
    };

    int n, m, src, dest;
    vector < Edge > edges;
    T zero, DEFAULT;
    vector < T > dist;

    BellmanFord(int _n = 0, int _m = 0, int _src = 1, int _dest = 1){
        n = _n, m = _m, src = _src, dest = _dest;
        zero = 0, DEFAULT = numeric_limits < T > :: max() / 2;
        dist.assign(n + 5, DEFAULT);
        edges.resize(m);
    }

    void read_edges(){
        cin >> edges;
    }

    void add_edge(int u, int v, T w){
        edges.emplace_back(u, v, w);
    }

    void build(){
        for(int i = 0; i < n; i++)
            for(auto& [u, v, w] : edges)
                dist[v] = min(dist[v], min(dist[u], zero) + w);
    }

    bool has_negative_cycle(){
        for(auto& [u, v, w] : edges)
            if(dist[v] > min(dist[u], zero) + w)
                return true;
        return false;
    } 

    T get_dist(int u){
        return dist[u];
    }

    T get_min_dist(){
        return *min_element(dist.begin(), dist.end());
    }
};

void Solve(){
    // Exaple usage of Bellman-Ford algorithm
    int n = 5;  // number of vertices
    int m = 6;  // number of edges
    int src = 1; // source vertex
    BellmanFord<int> bf(n, m, src);
    // Adding edges
    bf.add_edge(1, 2, 5);   // edge from vertex 1 to 2 with weight 5
    bf.add_edge(2, 3, -3);  // edge from vertex 2 to 3 with weight -3
    bf.add_edge(1, 3, 4);   // edge from vertex 1 to 3 with weight 4
    // Build the graph
    bf.build();
    // Check for negative cycles
    if(bf.has_negative_cycle()){
        cout << "Graph has negative cycle!" << endl;
        return;
    }
    // Get distance to specific vertex
    cout << "Distance to vertex 3: " << bf.get_dist(3) << endl;
    // Get minimum distance among all vertices
    cout << "Minimum distance: " << bf.get_min_dist() << endl;

}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int test_cases = 1;
    // cin >> test_cases;
    for(int tc = 1; tc <= test_cases; tc++){
        // cout << "Case #" << tc << ": ";
        Solve();
    }
    return 0;
}