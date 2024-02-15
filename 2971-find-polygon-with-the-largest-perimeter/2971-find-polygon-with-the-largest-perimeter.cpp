class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long sum=nums[0]+nums[1],ans=-1,n=nums.size(),last=-1;  
        for(int i=2;i<n;i++){
            if(sum>nums[i]){
                last=i;
                ans=sum+nums[i];
            }
            sum+=nums[i];
        }
        return ans;
        
    }
};