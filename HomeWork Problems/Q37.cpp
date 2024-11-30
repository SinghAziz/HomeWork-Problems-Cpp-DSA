#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;

void traversal(vector<int> &component, unordered_map<int, list<int> > &adjlist, unordered_map<int, bool> &visited, int Node) {
    component.push_back(Node);
    visited[Node] = true;

    for (auto it = adjlist[Node].begin(); it != adjlist[Node].end(); ++it) {
        int neighbor = *it;
        if (!visited[neighbor]) {
            traversal(component, adjlist, visited, neighbor);
        }
    }
}

vector<vector<int> > DFS(vector<pair<int, int> > &edges, int m, int n) {
    unordered_map<int, list<int> > adjlist;
    vector<vector<int> > answer;
    unordered_map<int, bool> visited;

    // Create adjacency list
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    // Include all nodes to handle isolated nodes
    for (int i = 0; i < n; i++) {
        adjlist[i];
    }

    // Traverse all components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            vector<int> component;
            traversal(component, adjlist, visited, i);
            answer.push_back(component);
        }
    }

    return answer;
}

int main() {
    int m, n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<pair<int, int> > edges(m); // Default initialization
    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    vector<vector<int> > solution = DFS(edges, m, n);

    cout << "DFS Traversal: " << endl;
    for (int i = 0; i < solution.size(); i++) {
        for (int j = 0; j < solution[i].size(); j++) {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
