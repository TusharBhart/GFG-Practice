class Solution{
    public:
    int lenOfLongSubarr(int nums[],  int n, int k) { 
        unordered_map<int, int> m;
        m[0] = -1;
        int s = 0, ans = 0;
        
        for(int i=0; i<n; i++) {
            s += nums[i];
            if(m.find(s - k) != m.end()) ans = max(ans, i - m[s - k]);
            if(m.find(s) == m.end()) m[s] = i;
        }
        return ans;
    } 

};