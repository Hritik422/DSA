class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>v;
        int n=nums.size(),i,product=1,z=0,y=0;
        for(i=0;i<n;i++){
            if(nums[i]!=0){
             product*=nums[i];
            }
        else
        z++;
        }
        if(z){
            for(i=0;i<n;i++){
                if(nums[i]!=0 || z>1)
                v.push_back(0); 
                else
                v.push_back(product);
            }
            return v;
        }
        for(i=0;i<n;i++)
        v.push_back(product/nums[i]);
        return v;
    }
};