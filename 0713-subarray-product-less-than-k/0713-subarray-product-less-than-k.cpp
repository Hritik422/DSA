class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0,j=0,n=nums.size(),prod=1,ans=0;
        while(j<n){
            prod*=nums[j];
            if(prod<k)ans+=j-i+1;
            else {
                while(i<j && prod>=k){
                    prod/=nums[i];
                    i++;
                }
                if(prod<k)ans+=j-i+1;
            }
            ++j;
        }
        return ans;
        
    }
};