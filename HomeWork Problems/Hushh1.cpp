#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <functional>

using namespace std;
const long long MOD = 1000000007LL;

int n, q, LOG;
vector<vector<int>> g;
vector<int> depth, tin, tout;
vector<vector<int>> up;
int timer = 0;

void dfs0(int v, int p){
  tin[v] = ++timer;
  up[v][0] = (p==-1? v : p);
  for(int i=1;i<LOG;i++) up[v][i] = up[ up[v][i-1] ][i-1];
  for(int to: g[v]) if(to!=p){
    depth[to] = depth[v]+1;
    dfs0(to, v);
  }
  tout[v] = timer;
}
inline bool is_anc(int u,int v){ return tin[u]<=tin[v] && tout[v]<=tout[u]; }
int lca(int a,int b){
  if(is_anc(a,b)) return a;
  if(is_anc(b,a)) return b;
  for(int i=LOG-1;i>=0;i--) if(!is_anc(up[a][i], b)) a = up[a][i];
  return up[a][0];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n>>q;
  g.assign(n+1,{});
  for(int i=0;i<n-1;i++){ int a,b; cin>>a>>b; g[a].push_back(b); g[b].push_back(a); }
  LOG = 1; while((1<<LOG)<=n) LOG++;
  depth.assign(n+1,0); tin.assign(n+1,0); tout.assign(n+1,0);
  up.assign(n+1, vector<int>(LOG));
  dfs0(1,-1);

  vector<int> nodes, st;
  vector<vector<int>> vt_adj(n+1);
  vector<int> used(n+1,0), vt_nodes;

  while(q--){
    int k; cin>>k;
    nodes.resize(k);
    for(int i=0;i<k;i++) cin>>nodes[i];
    if(k<2){ cout<<0<<"\n"; continue; }


    sort(nodes.begin(), nodes.end(), [&](int a,int b){ return tin[a]<tin[b]; });
    vector<int> ext = nodes;
    for(int i=0;i<(int)nodes.size()-1;i++) ext.push_back(lca(nodes[i], nodes[i+1]));
    sort(ext.begin(), ext.end(), [&](int a,int b){ return tin[a]<tin[b]; });
    ext.erase(unique(ext.begin(), ext.end()), ext.end());


    for(int v: ext){ vt_adj[v].clear(); used[v]=1; vt_nodes.push_back(v); }
    st.clear();
    for(int v: ext){
      if(st.empty()){ st.push_back(v); continue; }
      int w = lca(st.back(), v);
      while(!st.empty() && !is_anc(st.back(), v)){
        int u = st.back(); st.pop_back();
        int p = st.empty()? w : (is_anc(st.back(), w)? st.back() : w);
        if(st.empty() || st.back()!=p){ st.push_back(p); if(!used[p]){ used[p]=1; vt_adj[p].clear(); vt_nodes.push_back(p); } }
        vt_adj[p].push_back(u);
      }
      if(st.back()!=v) st.push_back(v);
    }
    while(st.size()>1){
      int u = st.back(); st.pop_back();
      vt_adj[st.back()].push_back(u);
    }
    int root = st.back();


    vector<char> inS(n+1,0);
    long long total=0;
    for(int v: nodes){ inS[v]=1; total = (total + v)%MOD; }

    // DFS on virtual tree to accumulate contributions
    long long ans = 0;
    function<long long(int)> dfs = [&](int v)->long long{
      long long sub = inS[v] ? v%MOD : 0;
      for(int c: vt_adj[v]){
        long long child = dfs(c);
        long long len = (depth[c]-depth[v])%MOD;
        long long left = child;
        long long right = (total - child + MOD)%MOD;
        ans = (ans + ((len*left)%MOD)*right)%MOD;
        sub = (sub + child)%MOD;
      }
      return sub;
    };
    dfs(root);
    cout<<ans%MOD<<"\n";


    for(int v: vt_nodes){ used[v]=0; }
    vt_nodes.clear();
  }
  return 0;
}
