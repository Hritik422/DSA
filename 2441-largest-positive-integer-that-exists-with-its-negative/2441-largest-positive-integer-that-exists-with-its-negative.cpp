class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        while(i<j){
            int res=nums[i]+nums[j];
            if(res==0)return nums[j];
            else if(res<0)i++;
            else j--;
        }
        return -1;
    }
};