
#include <iostream>
#include <vector>
using namespace std;

// Adjacency List

// undirected-unweighted adjacency list
vector<vector<int>> createUndirectedUnweightedList() {
    // numbers of vertex and edges
    int vertex, edges;
    cin >> vertex >> edges;

    vector<vector<int>> list(vertex);

    int u, v;
    for(int i = 0; i < edges; i++) {
        cin >> u >> v;
        list[u].push_back(v);
        list[v].push_back(u);
    }

    cout << "\n";
    return list;
}

// undirected-weighted adjacency list
vector<vector<pair<int, int>>> createUndirectedWeightedList() {
    int vertex, edges;
    cin >> vertex >> edges;

    vector<vector<pair<int, int>>> list(vertex);

    int u, v, w;
    for (int i = 0; i < edges; i++) {
        cin >> u >> v >> w;
        list[u].push_back({v, w});
        list[v].push_back({u, w});
    }

    cout << "\n";
    return list;
}

// directed-unweighted adjacency list
vector<vector<int>> createDirectedUnweightedList() {
    // numbers of vertex and edges
    int vertex, edges;
    cin >> vertex >> edges;

    vector<vector<int>> list(vertex);

    int u, v;
    for(int i = 0; i < edges; i++) {
        cin >> u >> v;
        list[u].push_back(v);
    }

    cout << "\n";
    return list;
}

// directed-weighted adjacency list
vector<vector<pair<int, int>>> createDirectedWeightedList() {
    // numbers of vertex and edges
    int vertex, edges;
    cin >> vertex >> edges;

    vector<vector<pair<int, int>>> list(vertex);

    int u, v, w;
    for(int i = 0; i < edges; i++) {
        cin >> u >> v >> w;
        list[u].push_back({v, w});
    }

    cout << "\n";
    return list;
}

void printGraph(const vector<vector<int>> &list) {
    int i = 0;
    for(const auto &r : list) {
        cout << i++ << " -> ";
        for(int c : r) {
            cout << c << " ";
        }
        cout << endl;
    }
}

void printDirectedWeightedGraph(const vector<vector<pair<int, int>>> &list) {
    int i = 0;
    for(const auto &r : list) {
        cout << i++ << " -> ";
        for(const auto &c : r) {
            cout << "{" << c.first << ", " << c.second << "}" << " ";
        }
        cout << endl;
    }
}

int main()
{

    // vector<vector<int>> list = createUndirectedUnweightedList();
    // vector<vector<pair<int, int>>> list = createUndirectedWeightedList();
    // vector<vector<int>> list = createDirectedUnweightedList();
    // printGraph(list);
    
    vector<vector<pair<int, int>>> list = createDirectedWeightedList();
    printDirectedWeightedGraph(list);
    return 0;
}
