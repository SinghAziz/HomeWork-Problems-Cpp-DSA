#include <iostream>
#include <map>
#include <queue>
#include <list>
#include <vector>
using namespace std;

void traversal(map <int, list<int> > &adjList, map<int, bool> &visited, vector<int> &answer, int start) {
    answer.push_back(start);
    visited[start] = true;
        // Visit all neighbors of the current node
        for (size_t i = 0; i < answer.size(); i++) {
            if (!visited[i]) {
                traversal(adjList, visited, answer,i); 
            }
        }
    }


vector<int> DFS(int n, vector<pair<int, int> > edges) {
    map<int, list<int> > adjList;
    map<int, bool> visited;
    vector<int> answer;

    // Creating adjacency list
    for (size_t i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Traversal of the graph
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            traversal(adjList, visited, answer, i);
        }
    }

    return answer;
}

int main() {
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<pair<int, int> > edges(m);
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = make_pair(u, v);
    }

    vector<int> solution = DFS(n, edges);

    cout << "DFS Traversal: " << endl;
    for (size_t i = 0; i < solution.size(); i++) {
        for ( size_t j=0;j<solution.size();j++){
            cout << solution[j] << " ";
        }
    }
    cout << endl;

    return 0;
}
