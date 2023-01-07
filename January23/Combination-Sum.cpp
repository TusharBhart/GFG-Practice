class Solution {
    void dfs(int i, int t, vector<int> &arr, vector<int> &v, set<vector<int>> &ans) {
        if(i < 0) {
            if(t == 0) {
                vector<int> temp = v;
                sort(temp.begin(), temp.end());
                ans.insert(temp);
            }
            return;
        }
        
        dfs(i - 1, t, arr, v, ans);
        if(arr[i] <= t){
            v.push_back(arr[i]);
            dfs(i, t - arr[i], arr, v, ans);
            v.pop_back();
        }
    }
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        set<int> temp(A.begin(), A.end());
        vector<int> vec(temp.begin(), temp.end());
        
        set<vector<int>> s;
        vector<int> v;
        int n = vec.size();
        
        dfs(n - 1, B, vec, v, s);
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};