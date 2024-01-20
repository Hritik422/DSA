class Solution {
public:
  int minFallingPathSum(vector<vector<int>>& arr)  {
        int n=arr.size(),m=arr[0].size(),ans=INT_MAX,i,j;
        for(i=1;i<n;i++){
            for(j=0;j<m;j++){
                if(j==0)arr[i][j]+=min(arr[i-1][j],arr[i-1][j+1]);
                else if(j==m-1)arr[i][j]+=min(arr[i-1][j],arr[i-1][j-1]);
                else arr[i][j]+=min({arr[i-1][j],arr[i-1][j+1],arr[i-1][j-1]});
            }
        }
        for(j=0;j<m;j++)ans=min(ans,arr[n-1][j]);
        return ans;
    }
};