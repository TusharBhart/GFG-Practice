class Solution{
    int dfs(int i, int t, int arr[], vector<vector<int>> &dp) {
        if(!t) return 1;
        if(!i) return arr[0] == t;
        if(dp[i][t] != -1) return dp[i][t];
        
        int notTake = dfs(i - 1, t, arr, dp);
        int take = t >= arr[i] ? dfs(i - 1, t - arr[i], arr, dp) : false;
        
        return dp[i][t] = take || notTake;
    }
public:
    int equalPartition(int N, int arr[]) {
        int sum = 0;
        for(int i=0; i<N; i++) sum += arr[i];
        
        if(sum % 2) return 0;
        int t = sum / 2;
        
        vector<vector<int>> dp(N, vector<int>(t + 1, -1));
        return dfs(N - 1, t, arr, dp);
    }
};