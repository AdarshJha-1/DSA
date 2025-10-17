#include <iostream>
#include <vector>
using namespace std;

// Adjacency matrix

// undirected-unweighted adjacency matrix
vector<vector<bool>> createUndirectedUnweightedMat() {
    // numbers of vertex and edges
    int vertex, edges;
    cin >> vertex >> edges;

    vector<vector<bool>> mat(vertex, vector<bool>(vertex, 0));

    int u, v;
    for(int i = 0; i < edges; i++) {
        cin >> u >> v;
        mat[u][v] = 1;
        mat[v][u] = 1;
    }

    cout << "\n";
    return mat;
}

// undirected-unweighted adjacency matrix
vector<vector<int>> createUndirectedWeightedMat() {
    // numbers of vertex and edges
    int vertex, edges;
    cin >> vertex >> edges;

    vector<vector<int>> mat(vertex, vector<int>(vertex, 0));

    int u, v, w;
    for(int i = 0; i < edges; i++) {
        cin >> u >> v >> w;
        mat[u][v] = w;
        mat[v][u] = w;
    }

    cout << "\n";
    return mat;
}

// directed-unweighted adjacency matrix
vector<vector<bool>> createDirectedUnweightedMat() {
    // numbers of vertex and edges
    int vertex, edges;
    cin >> vertex >> edges;

    vector<vector<bool>> mat(vertex, vector<bool>(vertex, 0));

    int u, v;
    for(int i = 0; i < edges; i++) {
        cin >> u >> v;
        mat[u][v] = 1;
    }

    cout << "\n";
    return mat;
}

// directed-weighted adjacency matrix
vector<vector<int>> createDirectedWeightedMat() {
    // numbers of vertex and edges
    int vertex, edges;
    cin >> vertex >> edges;

    vector<vector<int>> mat(vertex, vector<int>(vertex, 0));

    int u, v, w;
    for(int i = 0; i < edges; i++) {
        cin >> u >> v >> w;
        mat[u][v] = w;
    }

    cout << "\n";
    return mat;
}

void printUnweightedGraph(vector<vector<bool>> mat) {
    for(const auto &r : mat) {
        for(int c : r) {
            cout << c << " ";
        }
        cout << endl;
    }
}

void printWeightedGraph(vector<vector<int>> mat) {
    for(const auto &r : mat) {
        for(int c : r) {
            cout << c << " ";
        }
        cout << endl;
    }
}

int main()
{

    // vector<vector<bool>> mat = createUndirectedUnweightedMat();
    // vector<vector<int>> mat = createUndirectedWeightedMat();
    // vector<vector<bool>> mat = createDirectedUnweightedMat();
    vector<vector<int>> mat = createDirectedWeightedMat();
    printWeightedGraph(mat);


    return 0;
}
