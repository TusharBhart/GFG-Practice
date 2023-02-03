class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix, int r, int c){
        int dir = 1, i = 0, j = 0;
        while(true) {
            if(matrix[i][j]) {
                matrix[i][j] = 0;
                dir = dir == 4 ? 1 : dir + 1;
            }
            if(dir == 1) {
                j++;
                if(i < 0 || j < 0 || i == r || j == c) return {i, j - 1};
            }
            else if(dir == 2) {
                i++;
                if(i < 0 || j < 0 || i == r || j == c) return {i - 1, j};
            }
            else if(dir == 3) {
                j--;
                if(i < 0 || j < 0 || i == r || j == c) return {i, j + 1};
            }
            else if(dir == 4) {
                i--;
                if(i < 0 || j < 0 || i == r || j == c) return {i + 1, j};
            }
        }
        return {};
        
    }
};