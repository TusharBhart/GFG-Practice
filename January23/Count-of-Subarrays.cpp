class Solution{
public:
	// #define ll long long

	ll countSubarray(int arr[], int n, int k) {
	    ll ans = 0, prev = -1;
	    for(int i=0; i<n; i++) {
	        if(arr[i] > k) ans += i + 1, prev = i;
	        else ans += prev + 1;
	    }
	    return ans;
	}
};