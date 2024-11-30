// Breadth First Search
#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <queue>
#include <list>
#include<vector>    
using namespace std;

void traversal(unordered_map<int, list<int> > &adjList, unordered_map<int, bool> &visited,vector <int> &answer, int i )
{
    queue<int> q;
    q.push(i);
    visited[i]=1;

    while(!q.empty()){
        int frontval=q.front();
        q.pop();
        visited[frontval]=true;
        answer.push_back(frontval);

        for (auto i : adjList[frontval]){
            if (!visited[i]){
                q.push(i);
            }
        }
    }
}

vector<int> BFS(int n, vector  <pair<int, int> > edges)
{
    unordered_map<int, bool> visited;
    unordered_map<int,list<int> > adjList;
    vector<int> answer;

    //Creating Adjancey List
    for ( int i=0;i<n;i++){
        int u=edges[i].first;
        int v=edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    //Traveral of the whole adjacency list 
    for (int i=0;i<n;i++){
        if (!visited[i]){
            traversal(adjList, visited, answer, i);
        }
    }

    return answer;
}

int main()
{
    int m, n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;
    vector < pair<int, int> > edges(m, {0, 0});
    for (int i=0;i<m;i++){
        cin>>edges[i].first;    
        cin>>edges[i].second;
    }
    vector<int>solution=BFS(n, edges);
    cout<<"BFS Traversal: "<<endl;
    for ( auto i : solution){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}
