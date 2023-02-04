// Memoization
class Solution{
    int dfs(int i, int *arr, vector<int> &dp, int n) {
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        
        int notPick = dfs(i + 1, arr, dp, n);
        int pick = arr[i] + dfs(i + 2, arr, dp, n);
        
        return dp[i] = max(pick, notPick);
    }
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    vector<int> dp(n, -1);
	    return dfs(0, arr, dp, n);
	}
};

// Tabulation
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    vector<int> dp(n + 2);
	   // return dfs(0, arr, dp, n);
	   for(int i=n-1; i>=0; i--) {
	       int notPick = dp[i + 1];
	       int pick = arr[i] + dp[i + 2];
	       dp[i] = max(pick, notPick);
	   }
	   return dp[0];
	}
};

// Space Optimization
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    int a = 0, b = 0;
	    for(int i=n-1; i>=0; i--) {
	        int notPick = a;
	        int pick = arr[i] + b;
	        int c = max(pick, notPick);
	        b = a;
	        a = c;
	    }
	    return a;
	}
};