class Solution {
public:
    string longestString(vector<string> &words) {
        unordered_set<string> s(words.begin(), words.end());
        int l = 0;
        string ans;
        for(string w : words) {
            string t;
            int f = 0;
            for(char c : w) {
                t += c;
                if(s.find(t) == s.end()) {f = 1; break;}
            }
            if(!f) {
                if(w.size() > l) ans = w, l = w.size();
                else if(w.size() == l && w < ans) ans = w; 
            }
        }
        return ans;
    }
};