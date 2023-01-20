class Solution {
  public:
  int maxWeightCell(int n, vector<int> edge) {
      vector<int> d(n);
      for(int i=0; i<n; i++) {
          if(edge[i] != -1) d[edge[i]] += i;
      }
      int mx = 0, ans = 0;
      for(int i=n-1; i>=0; i--) {
          if(mx < d[i]) ans = i, mx = d[i];
      }
      return ans;
  }
};