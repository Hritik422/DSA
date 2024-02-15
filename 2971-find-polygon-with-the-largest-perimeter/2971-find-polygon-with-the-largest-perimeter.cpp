class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long sum=nums[0]+nums[1],ans=-1,n=nums.size(),last=-1;  
      //  for(int i=2;i<n;i++){
      //      if(sum<=nums[i]){
      //          if(last==i-1)ans=max(ans,sum);
      //          sum+=nums[i];
      //      }
      //      else{
      //          sum+=nums[i];
      //          last=i;
      //      }
      // }
        for(int i=2;i<n;i++){
            if(sum>nums[i]){
                last=i;
            }
            sum+=nums[i];
        }
        long long tot=0;
        for(int i=0;i<=last;i++)tot+=nums[i];
        if(last==-1)return last;
        return tot;
        
    }
};