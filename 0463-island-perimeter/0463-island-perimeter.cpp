class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int i,j,ans=0;
        for(i=0;i<grid.size();i++){
            for(j=0;j<grid[0].size();j++){
                int cnt=4;
                if(grid[i][j]==1){
                    if(i-1>=0 && grid[i-1][j]==1)cnt--;
                    if(i+1<grid.size() && grid[i+1][j]==1)cnt--;
                    if(j-1>=0 && grid[i][j-1]==1)cnt--;
                    if(j+1<grid[0].size() && grid[i][j+1]==1)cnt--;
                    ans+=cnt;
                }
            }
        }
        return ans;
    }
};