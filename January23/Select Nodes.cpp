class Solution{
    bool dfs(int node, int prnt, vector<int> adj[], unordered_set<int> &vis, int &ans) {
        bool f = false;
        for(int ad : adj[node]) {
            if(ad != prnt) f |= dfs(ad, node, adj, vis, ans);
        }
        if(f) {
            for(int ad : adj[node]) vis.insert(ad);
            vis.insert(node);
            vis.insert(prnt);
            ans++;
        }
        return !f;
    }
  public:
    int countVertex(int n, vector<vector<int>>edges){
        int root, ans = 0;
        vector<int> v(n + 1);
        vector<int> adj[n + 1];
        for(auto e : edges) v[e[1]]++, adj[e[0]].push_back(e[1]), adj[e[1]].push_back(e[0]);
        
        for(int i=1; i<=n; i++) {
            if(!v[i]) root = i;
        }
        unordered_set<int> vis;
        dfs(root, -1, adj, vis, ans);
        
        return ans;
    }
};