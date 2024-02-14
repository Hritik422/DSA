class Solution {
public:
    int findMin(vector<int>& nums) {
        //return *min_element(nums.begin(),nums.end());
        int i,n=nums.size(),mini=INT_MAX;
        for(i=0;i<n;i++)mini=min(mini,nums[i]);
        return mini;
    }
};
