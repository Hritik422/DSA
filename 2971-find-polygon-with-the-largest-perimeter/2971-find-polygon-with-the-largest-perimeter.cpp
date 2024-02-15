class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long sum=nums[0]+nums[1],ans=-1,n=nums.size(),last=-1;  
        for(int i=2;i<n;i++){
            if(sum<=nums[i]){
                if(last==i-1)ans=max(ans,sum);
                sum+=nums[i];
                //size++;
            }
            else{
                sum+=nums[i];
               // size++;
                last=i;
            }
        }
        if((sum-nums[n-1])>nums[n-1])
        ans=max(ans,sum);
        return ans;
    }
};