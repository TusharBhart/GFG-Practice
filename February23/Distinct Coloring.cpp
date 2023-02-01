class Solution{   
    long long int dfs(int i, int pre, int n, vector<vector<long long int>> &v, vector<vector<long long int>> &dp) {
        if(i == n) return 0;
        if(dp[i][pre] != -1) return dp[i][pre];
        
        long long int ans = LONG_LONG_MAX;
        for(int k=0; k<3; k++) {
            if(k == pre) continue;
            ans = min(ans, v[i][pre] + dfs(i + 1, k, n, v, dp));
        }
        return dp[i][pre] = ans;
    }
public:
    long long int distinctColoring(int N, int r[], int g[], int b[]){
        vector<vector<long long int>> v, dp(N, vector<long long int> (3, -1));
        for(int i=0; i<N; i ++) v.push_back({r[i], g[i], b[i]});
        
        long long int ans = LONG_LONG_MAX;
        for(int i=0; i<3; i++) {
            ans = min(ans, dfs(0, i, N, v, dp));
        }
        return ans;
    }
};