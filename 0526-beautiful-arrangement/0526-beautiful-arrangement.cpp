class Solution {
public:
   int vis[17]={0};
    int solve(vector<int>&nums,int inx, int n){
        if(inx==n+1){
            return 1;
        }
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(vis[nums[i]]==0 && (nums[i]%inx==0 || inx%nums[i]==0)){
                vis[nums[i]]=1;
                res+=solve(nums,inx+1,n);
                vis[nums[i]]=0;
            }
        }
        return res;
    }
    int countArrangement(int n) {
        vector<int>nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        
        int ans=solve(nums,1,n);
        return ans;
        
    }
};