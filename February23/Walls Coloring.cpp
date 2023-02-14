class Solution{
    int dfs(int i, int pre, vector<vector<int>> &colors, int n, vector<vector<int>> &dp) {
        if(i == n) return 0;
        if(dp[i][pre] != -1) return dp[i][pre];
        
        int mn = 1e9;
        for(int j=0; j<3; j++) {
            if(pre == j) continue;
            mn = min(mn, colors[i][j] + dfs(i + 1, j, colors, n, dp));
        }
        return dp[i][pre] = mn;
    }
public:
    int minCost(vector<vector<int>> &colors, int n) {
        vector<vector<int>> dp(n, vector<int>(3, -1));
        int ans = 1e9;
        for(int i=0; i<3; i++) {
            ans = min(ans, colors[0][i] + dfs(1, i, colors, n, dp));
        }
        return ans;
    }
};