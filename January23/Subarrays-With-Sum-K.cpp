class Solution{
    public:
    int findSubArraySum(int Arr[], int N, int k) {
        unordered_map<int, int> m;
        m[0] = 1;
        
        int ans = 0, s = 0;
        for(int i=0; i<N; i++) {
            s += Arr[i];
            if(m[s - k]) ans += m[s - k];
            m[s]++;
        }
        return ans;
    }
};