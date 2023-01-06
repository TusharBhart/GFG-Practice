class Solution {
    void dfs(int i, string &s, set<string> &ans) {
        if(i == s.size() - 1) {
            ans.insert(s);
            return;
        }
        
        for(int j=i; j<s.size(); j++) {
            swap(s[i], s[j]);
            dfs(i + 1, s, ans);
            swap(s[i], s[j]);
        }
    }
	public:
		vector<string>find_permutation(string s) {
		    set<string> st;
		    dfs(0, s, st);
		    vector<string> ans(st.begin(), st.end());
		    return ans;
		}
};