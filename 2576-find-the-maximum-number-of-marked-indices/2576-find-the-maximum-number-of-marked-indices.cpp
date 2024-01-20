class Solution {
public:
    int possible(vector<int>nums,int n){
        int i=0,j=n/2,ans=0;
        if(n%2)++j;
        while(j<n){
            if(nums[i]*2<=nums[j]){
                i++;
                j++;
                ans++;
            }
            else{
                j++;
            }
        }
        return ans*2;
    }
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),ans=0,j;
        return possible(nums,n);
    }
};
//2 4 5 9