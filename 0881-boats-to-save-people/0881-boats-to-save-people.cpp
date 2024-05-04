class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1,res=0;
        while(i<=j){
            if(i==j){
                res++;
                break;
            }
            int t=nums[i]+nums[j];
            if(t<=limit){
                res++;
                i++;
                j--;
            }
            else{
                res++;
                j--;
            }
            
        }
        return res;
    }
};