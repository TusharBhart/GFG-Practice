class Solution {
  public:
    vector<int> nextGreaterElement(int n, vector<int>& arr) {
        vector<int> ans(n);
        stack<int> s;
        for(int i=n-1; i>=0; i--) s.push(arr[i]);
        
        for(int i=n-1; i>=0; i--) {
            while(s.size() && s.top() <= arr[i]) s.pop();
            ans[i] = s.size() ? s.top() : -1;
            s.push(arr[i]);
        }
        
        return ans;
    }
};