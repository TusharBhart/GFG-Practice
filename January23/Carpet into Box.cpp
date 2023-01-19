class Solution{
    public:
    int carpetBox(int a, int b, int c, int d){
        int ans = 0;
        while(max(a, b) > max(c, d) || min(a, b) > min(c, d)) {
            if(a <= max(c, d) && b <= max(c, d)) {
                a > b ? b /= 2 : a /= 2;
                ans++;
                continue;
            }
            if(a <= c && b > d || a <= d && b > c) {
                b /= 2;
                ans++;
                continue;
            }
            if(b <= c && a > d || b <= d && a > c) {
                a /= 2;
                ans++;
                continue;
            }
            a > b ? a /= 2 : b /= 2;
            ans++;
        }
        return ans;
    }
};