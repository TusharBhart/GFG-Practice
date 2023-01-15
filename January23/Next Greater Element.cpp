class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        vector<long long> ans(n);
        stack<long long> s;
        
        for(int i=n-1; i>=0; i--) {
            while(s.size() && s.top() <= arr[i]) s.pop();
            ans[i] = s.size() ? s.top() : -1;
            s.push(arr[i]);
        }
        return ans;
    }
};