class Solution {
  public:
    int minRepeats(string a, string b) {
        if(a.size() >= b.size()) {
            if(a.find(b) != string :: npos) return 1;
            if((a + a).find(b) != string :: npos) return 2;
        }
        int ans = 1;
        string t = a;
        while(a.size() < b.size()) a += t, ans++;
        if(a.find(b) != string :: npos) return ans;
        if((a + t).find(b) != string :: npos) return ans + 1;
        return -1;
    }
};