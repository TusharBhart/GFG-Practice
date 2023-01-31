class Solution {
    vector<int> dx = {-1, 0, 1 ,0}, dy = {0, 1, 0, -1};
    bool dfs(int i, int j, int n ,vector<vector<int>> &g, vector<vector<int>> &vis) {
        if(i < 0 || j < 0 || i == n || j == n || vis[i][j] || !g[i][j]) return false;
        if(g[i][j] == 2) return true;
        vis[i][j] = 1;
        
        for(int k=0; k<4; k++) {
            int x = i + dx[k], y = j + dy[k];
            if(dfs(x, y, n, g, vis)) return true;
        }
        return false;
    }
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid)  {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n));
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) return dfs(i, j, n, grid, vis);
            }
        }
        return false;
    }
};