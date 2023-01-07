class Solution {
  public:
    long long countPairs(int n, int arr[], int k) {
        long long ans = 0;
        unordered_map<int, long long> m;
        
        for(int i=0; i<n; i++) {
            if(m.find(arr[i] % k) != m.end()) ans += m[arr[i] % k];
            m[arr[i] % k]++;
        }
        return ans;
    }
};