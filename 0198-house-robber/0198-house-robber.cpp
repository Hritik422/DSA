class Solution {
public:
   
    int cal(vector<int>& nums, int i, int n, vector<int>& dp){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        dp[i]=max(cal(nums,i+1,n,dp),nums[i]+cal(nums,i+2,n,dp));
        return dp[i];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return cal(nums,0,n,dp);
    }
};