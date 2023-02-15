class Solution {
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n) {
        vector<long long> l2r(n), r2l(n);
        stack<pair<long long, long long>> s1;
        
        for(int i=0; i<n; i++) {
            while(s1.size() && s1.top().first >= arr[i]) s1.pop();
            l2r[i] = s1.size() ? s1.top().second : -1;
            s1.push({arr[i], i});
        }
        while(s1.size()) s1.pop();
        
        for(int i=n-1; i>=0; i--) {
            while(s1.size() && s1.top().first >= arr[i]) s1.pop();
            r2l[i] = s1.size() ? s1.top().second : -1;
            s1.push({arr[i], i});
        }
        
        long long ans = 0;
        for(int i=0; i<n; i++) {
            int a = r2l[i], b = l2r[i];
            if(a == -1) a = n;
            // if(b == -1) b = 0;
            ans = max(ans, arr[i] * (a - b - 1));
        }
        return ans;
    }
};