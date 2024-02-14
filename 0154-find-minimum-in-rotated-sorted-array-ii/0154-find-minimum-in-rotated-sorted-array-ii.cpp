class Solution {
public:
    int findMin(vector<int>& nums) {
        //return *min_element(nums.begin(),nums.end());
        int n=nums.size();
        int start=0,end=n-1;
        while(start<end){
            if(nums[start]<nums[end])return nums[start];
            int mid=(start+end)/2;
            if(nums[mid]>nums[end])start=mid+1;
            else if(nums[start]==nums[end]){
                start++;
                end--;
            }
            else end=mid;
        }
        return nums[end];
        
    }
};
