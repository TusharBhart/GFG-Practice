class Solution {
  public:
    int solve(int N, int K, vector<int> &arr) {
        int s = 0, ans = 0;
        for(int i : arr) s += i;
        
        vector<int> factors;
        for(int i=1; i<=sqrt(s); i++) {
            if(s % i == 0) {
                factors.push_back(i);
                factors.push_back(s / i);
            }
        }
        
        for(int i=1; i<N; i++) arr[i] += arr[i - 1];
        
        for(int f : factors) {
            int cnt = 0;
            for(int i : arr) {
                if(i % f == 0) cnt++;
            }
            if(cnt >= K) ans = max(ans, f);
        }
        return ans;
    }
};