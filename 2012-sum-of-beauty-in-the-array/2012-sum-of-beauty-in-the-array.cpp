class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int i,n=nums.size(),ans=0;
        vector<int>temp(n),temp1(n);
        temp[0]=nums[0];
        for(i=1;i<n;i++){
            temp[i]=max(temp[i-1],nums[i]);
        }
        temp1[n-1]=nums[n-1];
        for(i=n-2;i>=0;i--){
            temp1[i]=min(temp1[i+1],nums[i]);
        }
        for(i=1;i<n-1;i++){
            if(nums[i]>temp[i-1] && nums[i]<temp1[i+1])ans+=2;
            else if(nums[i]<nums[i+1] && nums[i]>nums[i-1])ans++;
        }
        return ans;
        
    }
};