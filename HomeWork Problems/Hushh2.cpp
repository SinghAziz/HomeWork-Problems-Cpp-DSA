#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int INF = 1e9;

int N, Q;
vector<vector<int>> g;
vector<int> sz, parCentroid, levelCentroid;
vector<int> centroidPathHead; // not needed explicitly
vector<int> color; // 0 = black, 1 = white
vector<vector<int>> distToCentroid; // distToCentroid[l][v]
vector<int> used; // removed as centroid
vector<multiset<int>> bucket; // bucket[c]: distances from c to white nodes
vector<vector<int>> ancOnCentroid; // list of (centroid ancestor) per node
vector<vector<int>> distAlongCentroid; // matching distances to those ancestors

int dfsSize(int v, int p){
  sz[v]=1;
  for(int to: g[v]) if(to!=p && !used[to]) sz[v]+=dfsSize(to,v);
  return sz[v];
}
int findCentroid(int v, int p, int tot){
  for(int to: g[v]) if(to!=p && !used[to] && sz[to] > tot/2) return findCentroid(to,v,tot);
  return v;
}
void dfsDist(int v, int p, int depthLevel, int c, int d){
  if((int)distToCentroid.size()<=depthLevel) distToCentroid.push_back(vector<int>(N+1,0));
  distToCentroid[depthLevel][v]=d;
  ancOnCentroid[v].push_back(c);
  distAlongCentroid[v].push_back(d);
  for(int to: g[v]) if(to!=p && !used[to]) dfsDist(to,v,depthLevel,c,d+1);
}
void decompose(int start, int p, int depthLevel){
  int tot = dfsSize(start,-1);
  int c = findCentroid(start,-1,tot);
  used[c]=1;
  if((int)bucket.size()<=c) bucket.resize(N+1);
  parCentroid[c]= (p==-1? c : p);
  levelCentroid[c]=depthLevel;
  // distances from all nodes in this component to centroid c
  dfsDist(c,-1,depthLevel,c,0);
  for(int to: g[c]) if(!used[to]) decompose(to, c, depthLevel+1);
}
void updateToggle(int v){
  // flip color
  color[v]^=1;
  for(size_t i=0;i<ancOnCentroid[v].size();++i){
    int c = ancOnCentroid[v][i];
    int d = distAlongCentroid[v][i];
    if(color[v]){ // turned white: insert
      bucket[c].insert(d);
    }else{ // turned black: erase one occurrence
      auto it = bucket[c].find(d);
      if(it!=bucket[c].end()) bucket[c].erase(it);
    }
  }
}
int queryNearest(int v){
  int ans = INF;
  for(size_t i=0;i<ancOnCentroid[v].size();++i){
    int c = ancOnCentroid[v][i];
    int d = distAlongCentroid[v][i];
    if(!bucket[c].empty()){
      ans = min(ans, d + *bucket[c].begin());
    }
  }
  return (ans==INF? -1 : ans);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin>>N;
  g.assign(N+1,{});
  for(int i=0;i<N-1;i++){ int a,b; cin>>a>>b; g[a].push_back(b); g[b].push_back(a); }

  sz.assign(N+1,0);
  used.assign(N+1,0);
  parCentroid.assign(N+1,-1);
  levelCentroid.assign(N+1,0);
  color.assign(N+1,0);
  bucket.resize(N+1);
  ancOnCentroid.assign(N+1,{});
  distAlongCentroid.assign(N+1,{});

  decompose(1,-1,0);

  cin>>Q;
  while(Q--){
    int t,v; cin>>t>>v;
    if(t==0){
      updateToggle(v);
    }else{
      cout<<queryNearest(v)<<"\n";
    }
  }
  return 0;
}
