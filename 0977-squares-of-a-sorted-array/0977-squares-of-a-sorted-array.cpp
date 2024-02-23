class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i,n=nums.size();
        for(i=0;i<nums.size();i++){
            if(nums[i]>=0)break;
        }
        i=min(i,n-1);
        int j=i,k=i-1;
        vector<int>ans;
        while(j<n && k>=0){
            if(nums[j]*nums[j]<nums[k]*nums[k]){
                ans.push_back(nums[j]*nums[j]);
                j++;
            }
            else{
                ans.push_back(nums[k]*nums[k]);
                k--;
            }
        }
        while(j<n){ans.push_back(nums[j]*nums[j]);j++;}
        while(k>=0){ans.push_back(nums[k]*nums[k]);k--;}
        return ans;
        
    }
};