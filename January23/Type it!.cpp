class Solution {
  public:
    int minOperation(string s) {
        int d = 0, n = s.size();
        string t;
        for(int i=0; i<n; i++) {
            t += s[i];
            string r = s.substr(i + 1);
            if(r.find(t) != string :: npos) d = t.size();
        }
        return n - (d ? d - 1 : 0);
    }
};