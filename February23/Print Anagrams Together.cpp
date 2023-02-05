class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& w) {
        vector<vector<string>> ans;
        map<vector<int>, vector<string>> m;
        
        for(string s : w) {
            vector<int> v(26);
            for(char c : s) v[c - 'a']++;
            m[v].push_back(s);
        }
        
        for(auto i : m) {
            vector<string> v;
            for(string s : i.second) v.push_back(s);
            ans.push_back(v);
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};