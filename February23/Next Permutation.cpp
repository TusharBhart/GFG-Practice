class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> arr){
        int i = n - 2;
        for(i; i>=0; i--) {
            if(arr[i] < arr[i + 1]) break;
        }
        if(i == -1) {
            reverse(arr.begin(), arr.end());
            return arr;
        }
        
        for(int j=n-1; j>i; j--) {
            if(arr[j] > arr[i]) {
                swap(arr[i], arr[j]);
                break;
            }
        }
        reverse(arr.begin() + i + 1, arr.end());
        return arr;
    }
};
// 1 2 3 6 5 4
// 1 2 4 6 5 3
// 1 2 4 3 5 6