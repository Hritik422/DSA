class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3) return {};
        sort(nums.begin(),nums.end());
        vector<vector<int>>result;
        int n = nums.size()-3;
        
        for(int i=0;i<=n;i++)
        {
            if(i>0 && (nums[i]==nums[i-1]))
                continue;
            if(nums[i]>0)return result;
            int j = i+1;
            int k = nums.size()-1;
            while(j<k)
            {
                int sum = nums[j]+nums[k]+nums[i];
                if(sum==0)
                {
                    result.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    while(nums[j]==nums[j-1] && j<k) j++;
                }
                else if(sum<0)
                    j++;
                else k--;
            }
        }
        return result;
    }
};