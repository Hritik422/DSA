class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1;
        int maxi = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=maxi)
            {
                cnt--;
                if(cnt == 0)
                {
                    maxi = nums[i];
                    cnt = 1;
                }
            }
            else
                cnt++;
        }
        return maxi;
    }
};