class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n) {
    	map<int, int> m;
    	for(int i=0; i<n; i++) m[arr[i]]++, m[dep[i] + 1]--;
    	
    	int ans = 0, s = 0;
    	for(auto i : m) {
    	    s += i.second;
    	    if(s < 0) s = 0;
    	    ans = max(ans, s);
    	}
    	return ans;
    }
};