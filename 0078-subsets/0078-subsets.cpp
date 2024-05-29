class Solution {
public:
    void solve(vector<vector<int>>&result,vector<int>&nums,int ind,vector<int>& ans)
    {
        if(nums.size()==ind ){
            result.push_back(ans);
            return;
        }
        solve(result,nums,ind+1,ans);
        ans.push_back(nums[ind]);
        solve(result,nums,ind+1,ans);
        ans.pop_back();
        
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>>result;
        vector<int>ans;
        solve(result,nums,0,ans);
        return result; 
    }
};