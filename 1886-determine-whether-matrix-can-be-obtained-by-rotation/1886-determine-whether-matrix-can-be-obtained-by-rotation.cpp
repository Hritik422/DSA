class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int nRows = mat.size();
        int mCols = mat[0].size();

        for (int i = 0; i < nRows; i++) {
            for (int j = 0; j < i; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        for (int i = 0; i < nRows; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int k = 0; k < 4; k++) {
            if (mat == target) {
                return true; 
            }
            rotate(mat);
        }
        return false; 
    }
};