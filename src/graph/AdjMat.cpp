#include <iostream>
#include <vector>
using namespace std;

// Adjacency matrix

int main()
{
    int vertex, edges;
    cin >> vertex >> edges;

    /*
    // undirected unweighted graph
    vector<vector<bool>> mat(vertex, vector<bool>(vertex, 0));
    int u, v;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        mat[u][v] = 1;
        mat[v][u] = 1;
    }
        */

    for (auto &r : mat)
    {
        for (auto c : r)
        {
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}
