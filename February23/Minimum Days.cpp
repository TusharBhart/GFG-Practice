class Solution {
  public:
    int getMinimumDays(int n,string s, vector<int> &p) {
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(p[i] - 1 >= 0 && s[p[i]] != '?' && s[p[i] - 1] == s[p[i]]) s[p[i]] = '?', ans = i + 1;
            else if(p[i] + 1 < n && s[p[i]] != '?' && s[p[i] + 1] == s[p[i]]) s[p[i]] = '?', ans = i + 1;
        }
        return ans;
    }
};