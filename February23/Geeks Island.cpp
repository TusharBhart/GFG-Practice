//User function Template for C++

class Solution{  
    void dfs(int i, int j, vector<vector<int>> &mat, int n, int m, vector<vector<int>> &vis) {
        vis[i][j] = 1;
        if(i - 1 >= 0 && mat[i - 1][j] >= mat[i][j] && !vis[i - 1][j]) dfs(i - 1, j, mat, n, m, vis);
        if(i + 1 < n && mat[i + 1][j] >= mat[i][j] && !vis[i + 1][j]) dfs(i + 1, j, mat, n, m, vis);
        if(j - 1 >= 0 && mat[i][j - 1] >= mat[i][j] && !vis[i][j - 1]) dfs(i, j - 1, mat, n, m, vis);
        if(j + 1 < m && mat[i][j + 1] >= mat[i][j] && !vis[i][j + 1]) dfs(i, j + 1, mat, n, m, vis);
    }
public:
    int water_flow(vector<vector<int>> &mat,int n,int m){
        vector<vector<int>> vis1(n, vector<int>(m)), vis2(n, vector<int>(m));
        
        for(int i=0; i<m; i++) {
            if(!vis1[0][i]) dfs(0, i, mat, n, m, vis1);
        }
        for(int i=0; i<n; i++) {
            if(!vis1[i][0]) dfs(i, 0, mat, n, m, vis1);
        }
        for(int i=0; i<m; i++) {
            if(!vis2[n - 1][i]) dfs(n - 1, i, mat, n, m, vis2);
        }
        for(int i=0; i<n; i++) {
            if(!vis2[i][m - 1]) dfs(i, m - 1, mat, n, m, vis2);
        }
        
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(vis1[i][j] && vis2[i][j]) ans++;
            }
        }
        return ans;
    }
};
