class Solution {
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n) {
        vector<char> l, u;
        for(char c : str) {
            if(isupper(c)) u.push_back(c);
            else l.push_back(c);
        }
        sort(l.begin(), l.end());
        sort(u.begin(), u.end());
        
        string ans;
        int i = 0, j = 0;
        for(char c : str) {
            if(isupper(c)) ans += u[j++];
            else ans += l[i++];
        }
        return ans;
    }
};