class Solution {
    void dfs(int i, int j, vector<vector<int>> &matrix, int n, int m) {
        if(i < 0 || i == n || j < 0 || j == m || matrix[i][j] == -1 || !matrix[i][j]) return;
        
        matrix[i][j] = -1;
        dfs(i + 1, j, matrix, n, m);
        dfs(i, j + 1, matrix, n, m);
        dfs(i - 1, j, matrix, n, m);
        dfs(i, j - 1, matrix, n, m);
    }
    
    public:
    int closedIslands(vector<vector<int>>& matrix, int n, int m) {
        for(int i=0; i<m; i++) {
            if(matrix[0][i]) dfs(0, i, matrix, n, m);
        }
        for(int i=0; i<m; i++) {
            if(matrix[n - 1][i]) dfs(n - 1, i, matrix, n, m);
        }
        for(int i=0; i<n; i++) {
            if(matrix[i][0]) dfs(i, 0, matrix, n, m);
        }
        for(int i=0; i<n; i++) {
            if(matrix[i][m - 1]) dfs(i, m - 1, matrix, n, m);
        }
        
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == 1) ans++, dfs(i, j, matrix, n, m);
            }
        }
        return ans;
    }
};