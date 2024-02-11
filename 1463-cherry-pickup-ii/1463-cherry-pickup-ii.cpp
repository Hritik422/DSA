class Solution {
public:
    int dp[71][71][71];

    int solve(int r, int c1, int c2, vector<vector<int>> &grid,int m,int n) {
        if(r>m-1 || c1>n-1 || c2>n-1 || c1<0 || c2<0) return 0;
        if(dp[r][c1][c2]!=-1) return dp[r][c1][c2];
        int cherries=0;
        if(c1==c2) {
            cherries+=grid[r][c1];
        }
        else {
            cherries+=grid[r][c1]+grid[r][c2];
        }
        if(r == m-1) return dp[r][c1][c2] = cherries;
        int choice1 = solve(r+1, c1+1, c2-1, grid,m,n);
        int choice2 = solve(r+1, c1+1, c2, grid,m,n);
        int choice3 = solve(r+1, c1+1, c2+1, grid,m,n);
        int choice4 = solve(r+1, c1, c2-1, grid,m,n);
        int choice5 = solve(r+1, c1, c2, grid,m,n);
        int choice6 = solve(r+1, c1, c2+1, grid,m,n);
        int choice7 = solve(r+1, c1-1, c2-1, grid,m,n);
        int choice8 = solve(r+1, c1-1, c2, grid,m,n);
        int choice9 = solve(r+1, c1-1, c2+1, grid,m,n);
        cherries+=max({choice1, choice2, choice3, choice4, choice5, choice6, choice7, choice8, choice9});
        return dp[r][c1][c2]=cherries;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        int m = grid.size(),n = grid[0].size();
        int ans = solve(0, 0, grid[0].size() - 1, grid,m,n);

        return ans;
    }
};