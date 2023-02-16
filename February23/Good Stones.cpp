//User function Template for C++
class Solution{
    bool dfs(int node,vector<int> &arr, vector<int> &vis, int n, vector<int> &nodes) {
        if(node < 0 || node >= n) return true;
        if(vis[node] == 2) return false;
        
        vis[node] = 2;
        nodes.push_back(node);
        if(dfs(node + arr[node], arr, vis, n, nodes)) return true;
        return false;
    }
public:
    int goodStones(int n,vector<int> &arr){
        vector<int> vis(n);
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(vis[i] == 2) continue;
            int cnt = 0;
            vector<int> nodes;
            bool b = dfs(i, arr, vis, n, nodes);
            if(b) {
                for(int i : nodes) vis[i] = 1;
            }
        }
        for(int i : vis) ans += i == 1;
        return ans;
    }  
};
