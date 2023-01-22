class Solution {
  public:
    string removePair(string s) {
        string ans;
        for(char c : s) {
            if(ans.back() == c) ans.pop_back();
            else ans += c;
        }
        return ans.size() ? ans : "-1";
    }
};